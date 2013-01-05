#include <canny/console.h>
#include <canny/log.h>
using namespace v8;

void canny::console::log(int prio, const Arguments& args) {
    HandleScope handleScope;

    int length = args.Length();
    if (length == 0) {
        return;
    }

    Handle<String> msg = args[0]->ToString();
    for (int i = 1; i < length; ++i) {
        msg = String::Concat(String::Concat(msg, String::New(" ")), args[i]->ToString());
    } 
    String::Utf8Value utf8(msg);

    LOG(prio, *utf8);
}

Handle<Value> canny::console::debug(const Arguments& args) {
    canny::console::log(ANDROID_LOG_DEBUG, args);
    return Undefined();
}

Handle<Value> canny::console::info(const Arguments& args) {
    canny::console::log(ANDROID_LOG_INFO, args);
    return Undefined();
}

Handle<Value> canny::console::warn(const Arguments& args) {
    canny::console::log(ANDROID_LOG_WARN, args);
    return Undefined();
}

Handle<Value> canny::console::error(const Arguments& args) {
    canny::console::log(ANDROID_LOG_ERROR, args);
    return Undefined();
}

Handle<Value> canny::console::assert(const Arguments& args) {
    HandleScope handleScope;

    if (args[0]->ToBoolean()->Value()) {
        return Undefined();
    }

    Handle<String> msg = String::New("Assertion failed:");
    int length = args.Length();
    for (int i = 1; i < length; ++i) {
        msg = String::Concat(String::Concat(msg, String::New(" ")), args[i]->ToString());
    } 
    String::Utf8Value utf8(msg);
    LOGE(*utf8);

    return Undefined();
}

Handle<Value> canny::console::trace(const Arguments& args) {
    HandleScope handleScope;

    Handle<StackTrace> trace = StackTrace::CurrentStackTrace(20);
    LOGD("console.trace():");

    int count = trace->GetFrameCount();
    Handle<StackFrame> frame;
    for (int i = 0; i < count; ++i) {
        frame = trace->GetFrame(i);
        Handle<String> functionName = frame->GetFunctionName();
        Handle<String> fileName = frame->GetScriptName();

        if (functionName->Length() < 1) {
            LOGDF("\tat anonymous function (%s:%d)", *(String::Utf8Value(fileName)), frame->GetLineNumber());
        } else {
            LOGDF("\tat function %s (%s:%d)", *(String::Utf8Value(functionName)), *(String::Utf8Value(fileName)), frame->GetLineNumber());
        }
    }
    
    return Undefined();
}

Handle<ObjectTemplate> canny::console::createConsoleObjectTemplate() {
    Handle<ObjectTemplate> console = ObjectTemplate::New();
    console->Set(String::New("log"), FunctionTemplate::New(canny::console::debug));
    console->Set(String::New("debug"), FunctionTemplate::New(canny::console::debug));
    console->Set(String::New("info"), FunctionTemplate::New(canny::console::info));
    console->Set(String::New("warn"), FunctionTemplate::New(canny::console::warn));
    console->Set(String::New("error"), FunctionTemplate::New(canny::console::error));
    console->Set(String::New("assert"), FunctionTemplate::New(canny::console::assert));
    console->Set(String::New("trace"), FunctionTemplate::New(canny::console::trace));
    return console;
}
