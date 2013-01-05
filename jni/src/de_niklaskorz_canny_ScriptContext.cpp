#include <canny/de_niklaskorz_canny_ScriptContext.h>
#include <canny/console.h>
#include <v8.h>

using namespace v8;

JNIEXPORT jlong JNICALL Java_de_niklaskorz_canny_ScriptContext_createNativeContext
  (JNIEnv *, jclass) {
    HandleScope handleScope;

    Handle<ObjectTemplate> global = ObjectTemplate::New();
    global->Set(String::New("console"), createConsoleObject());

    Persistent<Context> context = Context::New(NULL, global);
    return (jlong)(*context);
}

JNIEXPORT void JNICALL Java_de_niklaskorz_canny_ScriptContext_eval
  (JNIEnv *, jobject, jstring) {
    HandleScope handleScope;

    jclass objClass = env->GetObjectClass(obj);
    jfieldID contextFieldId = env->GetFieldID(objClass, "nativeContext", "J");
    Context *contextPtr = (Context *)(env->GetLongField(obj, contextFieldId));
    Persistent<Context> context(contextPtr);

    Context::Scope contextScope(context);
    Handle<String> source = String::New(env->GetStringUTFChars(code, 0));
    Handle<Script> script = Script::Compile(source, String::New("test.js"));
    Handle<Value> result = script->Run();
}
