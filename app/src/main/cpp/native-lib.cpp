#include <jni.h>
//#include <string>

#include <android/log.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "IRgByPixelisation/videoProcessing.hpp"
//#include "IRgByPixelisation/main.hpp"

#define TAG "NativeLib"

extern "C"
//JNIEXPORT jstring
JNIEXPORT void
JNICALL
Java_com_example_AndroidOpenCvOpenClNativeExample_MainActivity_adaptiveThresholdFromJNI(
        JNIEnv *env,
        jobject thiz/* this */,
        jlong matAdrr) {
    //std::string hello = "Hello from C++";
    //return env->NewStringUTF(hello.c_str());

    // get Mat from raw address
    cv::Mat &mat = *(cv::Mat *) matAdrr;
    clock_t begin = clock();

    cv::adaptiveThreshold(mat, mat, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY_INV, 21, 5);
    // log computation time to Android Logcat
    double totalTime = double(clock() - begin) / CLOCKS_PER_SEC;
    __android_log_print(ANDROID_LOG_INFO, TAG, "adaptiveThreshold computation time = %f seconds\n",
                        totalTime);
}


//extern "C"
//JNIEXPORT void JNICALL
//Java_com_example_AndroidOpenCvOpenClNativeExample_MainActivity_getInstaceOfEnvJNI(JNIEnv *env,
//                                                                                  jobject thiz) {
//    cl_mem detectionFlag;
//}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_AndroidOpenCvOpenClNativeExample_NAFFD_adaptiveThresholdFromJNI(JNIEnv *env,
                                                                                 jobject thiz,
                                                                                 jlong matAdrr) {
    //std::string hello = "Hello from C++";
    //return env->NewStringUTF(hello.c_str());

    // get Mat from raw address
    cv::Mat &mat = *(cv::Mat *) matAdrr;

    clock_t begin = clock();

    cv::adaptiveThreshold(mat, mat, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY_INV, 21, 5);
    // log computation time to Android Logcat
    double totalTime = double(clock() - begin) / CLOCKS_PER_SEC;
    __android_log_print(ANDROID_LOG_INFO, TAG, "adaptiveThreshold computation time = %f seconds\n",
                        totalTime);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_AndroidOpenCvOpenClNativeExample_NAFFD_getInstanceOfEnvRunJNI(JNIEnv *env,
                                                                               jobject thiz) {
    assert((env) != nullptr);
    jclass klazz = (env)->GetObjectClass(thiz);
    assert((klazz) != nullptr);

    jfieldID thizModelStrJFieldID = env->GetFieldID(klazz, "modelStr", "J");
    assert(thizModelStrJFieldID != nullptr);
    jlong jModelStr =  (env)->GetLongField(thiz,thizModelStrJFieldID);
    modelStruct *p_modelStruct = (modelStruct *)jModelStr;

//    jfieldID thizp_numPlatformsJFieldID = env->GetFieldID(klazz, "p_numPlatforms", "J");
//    assert(thizp_numPlatformsJFieldID != nullptr);
//    jlong jp_numPlatforms =  (env)->GetLongField(thiz,thizp_numPlatformsJFieldID);
//    cl_uint *p_numPlatforms = (cl_uint *)jp_numPlatforms;
//
//    jfieldID thizplatformsJFieldID = env->GetFieldID(klazz, "platforms", "J");
//    assert(thizplatformsJFieldID != nullptr);
//    jlong jplatforms =  (env)->GetLongField(thiz,thizplatformsJFieldID);
//    cl_platform_id *platforms = (cl_platform_id *)jplatforms;
//
//    jfieldID thizp_contextsJFieldID = env->GetFieldID(klazz, "p_contexts", "J");
//    assert(thizp_contextsJFieldID != nullptr);
//    jlong jp_contexts =  (env)->GetLongField(thiz,thizp_contextsJFieldID);
//    cl_context *p_contexts = (cl_context *)jp_contexts;
//
//    jfieldID thizp_kernelJFieldID = env->GetFieldID(klazz, "p_kernel", "J");
//    assert(thizp_kernelJFieldID != nullptr);
//    jlong jp_kernel =  (env)->GetLongField(thiz,thizp_kernelJFieldID);
//    cl_kernel *p_kernel = (cl_kernel *)jp_kernel;
//
//    jfieldID thizp_kernel1JFieldID = env->GetFieldID(klazz, "p_kernel1", "J");
//    assert(thizp_kernel1JFieldID != nullptr);
//    jlong jp_kernel1 =  (env)->GetLongField(thiz,thizp_kernel1JFieldID);
//    cl_kernel *p_kernel1 = (cl_kernel *)jp_kernel1;
//
//    jfieldID thizp_kernel2JFieldID = env->GetFieldID(klazz, "p_kernel2", "J");
//    assert(thizp_kernel2JFieldID != nullptr);
//    jlong jp_kernel2 =  (env)->GetLongField(thiz,thizp_kernel2JFieldID);
//    cl_kernel *p_kernel2 = (cl_kernel *)jp_kernel2;
//
//    jfieldID thizp_kernel3JFieldID = env->GetFieldID(klazz, "p_kernel3", "J");
//    assert(thizp_kernel3JFieldID != nullptr);
//    jlong jp_kernel3 =  (env)->GetLongField(thiz,thizp_kernel3JFieldID);
//    cl_kernel *p_kernel3 = (cl_kernel *)jp_kernel3;
//
//    jfieldID thizp_command_queueJFieldID = env->GetFieldID(klazz, "p_commandsArray", "J");
//    assert(thizp_command_queueJFieldID != nullptr);
//    jlong jp_command_queue =  (env)->GetLongField(thiz,thizp_command_queueJFieldID);
//    cl_command_queue **p_command_queue = (cl_command_queue **)jp_command_queue;

//    jfieldID thizlocal4PixelMaxWrokGroupSizeJFieldID = env->GetFieldID(klazz, "local4PixelMaxWrokGroupSize", "J");
//    assert(thizlocal4PixelMaxWrokGroupSizeJFieldID != nullptr);
//    jlong jlocal4PixelMaxWrokGroupSize =  (env)->GetLongField(thiz,thizlocal4PixelMaxWrokGroupSizeJFieldID);
//    size_t* p_local = (size_t *)malloc(sizeof(size_t));
//    *p_local=0;
//    size_t *local4PixelMaxWrokGroupSize = (size_t *)jlocal4PixelMaxWrokGroupSize;

    jfieldID thizp_countJFieldID = env->GetFieldID(klazz, "p_count", "J");
    assert( thizp_countJFieldID != nullptr);
    jfieldID thizcountJFieldID = env->GetFieldID(klazz, "count", "I");
    assert(thizcountJFieldID != nullptr);
    int *p_count = (int *)malloc(sizeof(int));
    jint jcount=(env)->GetIntField(thiz,thizcountJFieldID);
    *p_count = (int)jcount;

    jfieldID thizp_countResizedJFieldID = env->GetFieldID(klazz, "p_countResized", "J");
    assert( thizp_countResizedJFieldID != nullptr);
    jfieldID thizcountResizedJFieldID = env->GetFieldID(klazz, "countResized", "I");
    assert(thizcountResizedJFieldID != nullptr);
    int *p_countResized = (int *)malloc(sizeof(int));
    jint jcountResized=(env)->GetIntField(thiz,thizcountResizedJFieldID);
    *p_countResized = (int)jcountResized;

    jfieldID thizp_imgWidthJFieldID = env->GetFieldID(klazz, "p_imgWidth", "J");
    assert( thizp_imgWidthJFieldID != nullptr);
    jfieldID thizimgWidthJFieldID = env->GetFieldID(klazz, "width", "I");
    assert(thizimgWidthJFieldID != nullptr);
    int *p_imgWidth = (int *)malloc(sizeof(int));
    jint jimgWidth=(env)->GetIntField(thiz,thizimgWidthJFieldID);
    *p_imgWidth = (int)jimgWidth;

    jfieldID thizp_imgWidthResizedJFieldID = env->GetFieldID(klazz, "p_imgWidthResized", "J");
    assert( thizp_imgWidthResizedJFieldID != nullptr);
    jfieldID thizimgWidthResizedJFieldID = env->GetFieldID(klazz, "imgWidthResized", "I");
    assert(thizimgWidthResizedJFieldID != nullptr);
    int *p_imgWidthResized = (int *)malloc(sizeof(int));
    jint jimgWidthResized=(env)->GetIntField(thiz,thizimgWidthResizedJFieldID);
    *p_imgWidthResized = (int)jimgWidthResized;

    jfieldID thizp_imgHeightJFieldID = env->GetFieldID(klazz, "p_imgHeight", "J");
    assert( thizp_imgHeightJFieldID != nullptr);
    jfieldID thizimgHeightJFieldID = env->GetFieldID(klazz, "height", "I");
    assert(thizimgHeightJFieldID != nullptr);
    int *p_imgHeight = (int *)malloc(sizeof(int));
    jint jimgHeight=(env)->GetIntField(thiz,thizimgHeightJFieldID);
    *p_imgHeight = (int)jimgHeight;


    jfieldID thizp_imgHeightResizedJFieldID = env->GetFieldID(klazz, "p_imgHeightResized", "J");
    assert( thizp_imgHeightResizedJFieldID != nullptr);
    jfieldID thizimgHeightResizedJFieldID = env->GetFieldID(klazz, "imgHeightResized", "I");
    assert(thizimgHeightResizedJFieldID != nullptr);
    int *p_imgHeightResized = (int *)malloc(sizeof(int));
    jint jimgHeightResized=(env)->GetIntField(thiz,thizimgHeightResizedJFieldID);
    *p_imgHeightResized = (int)jimgHeightResized;

    jfieldID thizp_resizedFactorJFieldID = env->GetFieldID(klazz, "p_resizedFactor", "J");
    assert( thizp_resizedFactorJFieldID != nullptr);
    jfieldID thizresizedFactorJFieldID = env->GetFieldID(klazz, "resizedFactor", "I");
    assert(thizresizedFactorJFieldID != nullptr);
    int *p_resizedFactor = (int *)malloc(sizeof(int));
    jint jresizedFactor=(env)->GetIntField(thiz,thizresizedFactorJFieldID);
    *p_resizedFactor = (int)jresizedFactor;

    jfieldID thizp_thresholdEntireImageJFieldID = env->GetFieldID(klazz, "p_thresholdEntireImage", "J");
    assert( thizp_thresholdEntireImageJFieldID != nullptr);
    jfieldID thizthresholdEntireImageJFieldID = env->GetFieldID(klazz, "thresholdEntireImage", "I");
    assert(thizthresholdEntireImageJFieldID != nullptr);
    int *p_thresholdEntireImage = (int *)malloc(sizeof(int));
    jint jthresholdEntireImage=(env)->GetIntField(thiz,thizthresholdEntireImageJFieldID);
    *p_thresholdEntireImage = (int)jthresholdEntireImage;

    jfieldID thizp_thresholdROIFactorJFieldID = env->GetFieldID(klazz, "p_thresholdROIFactor", "J");
    assert( thizp_thresholdROIFactorJFieldID != nullptr);
    jfieldID thizthresholdROIFactorJFieldID = env->GetFieldID(klazz, "thresholdROIFactor", "D");
    assert(thizthresholdROIFactorJFieldID != nullptr);
    double *p_thresholdROIFactor = (double *)malloc(sizeof(double));
    jdouble jthresholdROIFactor=(env)->GetDoubleField(thiz,thizthresholdROIFactorJFieldID);
    *p_thresholdROIFactor = (double)jthresholdROIFactor;

//    jfieldID thizp_inputJFieldID = env->GetFieldID(klazz, "p_input", "J");
//    assert(thizp_inputJFieldID != nullptr);
//    jlong jp_input =  (env)->GetLongField(thiz,thizp_inputJFieldID);
//    cl_mem *p_input = (cl_mem *)jp_input;
//
//    jfieldID thizp_outputJFieldID = env->GetFieldID(klazz, "p_output", "J");
//    assert(thizp_outputJFieldID != nullptr);
//    jlong jp_output =  (env)->GetLongField(thiz,thizp_outputJFieldID);
//    cl_mem *p_output = (cl_mem *)jp_output;
//
//    jfieldID thizp_inputHist0JFieldID = env->GetFieldID(klazz, "p_inputHist0", "J");
//    assert(thizp_inputHist0JFieldID != nullptr);
//    jlong jp_inputHist0 =  (env)->GetLongField(thiz,thizp_inputHist0JFieldID);
//    cl_mem *p_inputHist0 = (cl_mem *)jp_inputHist0;
//
//    jfieldID thizp_inputHist1JFieldID = env->GetFieldID(klazz, "p_inputHist1", "J");
//    assert(thizp_inputHist1JFieldID != nullptr);
//    jlong jp_inputHist1 =  (env)->GetLongField(thiz,thizp_inputHist1JFieldID);
//    cl_mem *p_inputHist1 = (cl_mem *)jp_inputHist1;
//
//    jfieldID thizp_inputHist2JFieldID = env->GetFieldID(klazz, "p_inputHist2", "J");
//    assert(thizp_inputHist2JFieldID != nullptr);
//    jlong jp_inputHist2 =  (env)->GetLongField(thiz,thizp_inputHist2JFieldID);
//    cl_mem *p_inputHist2 = (cl_mem *)jp_inputHist2;
//
//    jfieldID thizp_output1JFieldID = env->GetFieldID(klazz, "p_output1", "J");
//    assert(thizp_output1JFieldID != nullptr);
//    jlong jp_output1 =  (env)->GetLongField(thiz,thizp_output1JFieldID);
//    cl_mem *p_output1 = (cl_mem *)jp_output1;
//
//    jfieldID thizp_output3JFieldID = env->GetFieldID(klazz, "p_output3", "J");
//    assert(thizp_output3JFieldID != nullptr);
//    jlong jp_output3 =  (env)->GetLongField(thiz,thizp_output3JFieldID);
//    cl_mem *p_output3 = (cl_mem *)jp_output3;
//
//    jfieldID thizp_changeArrayClMemJFieldID = env->GetFieldID(klazz, "p_changeArrayClMem", "J");
//    assert(thizp_changeArrayClMemJFieldID != nullptr);
//    jlong jp_changeArrayClMem =  (env)->GetLongField(thiz,thizp_changeArrayClMemJFieldID);
//    cl_mem *p_changeArrayClMem = (cl_mem *)jp_changeArrayClMem;
//
//    jfieldID thizp_detectionFlagJFieldID = env->GetFieldID(klazz, "p_detectionFlag", "J");
//    assert(thizp_detectionFlagJFieldID != nullptr);
//    jlong jp_detectionFlag =  (env)->GetLongField(thiz,thizp_detectionFlagJFieldID);
//    cl_mem *p_detectionFlag = (cl_mem *)jp_detectionFlag;
//
//    jfieldID thizp_detectionFlagROIJFieldID = env->GetFieldID(klazz, "p_detectionFlagROI", "J");
//    assert(thizp_detectionFlagROIJFieldID != nullptr);
//    jlong jp_detectionFlagROI =  (env)->GetLongField(thiz,thizp_detectionFlagROIJFieldID);
//    cl_mem *p_detectionFlagROI = (cl_mem *)jp_detectionFlagROI;

    jfieldID thizfaceArraySizeJFieldID = env->GetFieldID(klazz, "facesArraySize", "J");
    assert(thizfaceArraySizeJFieldID != nullptr);
//    jlong jfaceArraySize =  (env)->GetIntField(thiz,thizfaceArraySizeJFieldID);
    int* p_faceArraySize = (int *)malloc(sizeof(int));
    *p_faceArraySize=0;

//    jfieldID thizchangesDetectionJFieldID = env->GetFieldID(klazz, "changesDetection", "I");
//    assert(thizchangesDetectionJFieldID != nullptr);
    jfieldID thizp_changesDetectionJFieldID = env->GetFieldID(klazz, "p_changesDetection", "J");
    assert(thizp_changesDetectionJFieldID != nullptr);
    int* p_changesDetection = (int *)malloc(sizeof(int));
    *p_changesDetection=1;


//    jfieldID thizchangesDetectionROIJFieldID = env->GetFieldID(klazz, "changesDetectionROI", "I");
//    assert(thizchangesDetectionROIJFieldID != nullptr);
    jfieldID thizp_changesDetectionROIJFieldID = env->GetFieldID(klazz, "p_changesDetectionROI", "J");
    assert(thizp_changesDetectionROIJFieldID != nullptr);
    int* p_changesDetectionROI = (int *)malloc(sizeof(int));
    *p_changesDetectionROI=1;

    jfieldID thizchangeArrayJFieldID = env->GetFieldID(klazz, "changeArray", "J");
    assert(thizchangeArrayJFieldID != nullptr);
//    jlong jchangeArray =  (env)->GetIntField(thiz,thizchangeArrayJFieldID);
    int* p_changeArray = (int *)malloc(sizeof(int));
    p_changeArray[0]=0;
    p_changeArray[1]=0;
    p_changeArray[2]=0;

    jfieldID thizp_cntrJFieldID = env->GetFieldID(klazz, "p_cntr", "J");
    assert( thizp_cntrJFieldID != nullptr);
    jfieldID thizcntrJFieldID = env->GetFieldID(klazz, "cntr", "I");
    assert(thizcntrJFieldID != nullptr);
    int *p_cntr = (int *)malloc(sizeof(int));
    jint jcntr=(env)->GetIntField(thiz,thizcntrJFieldID);
    *p_cntr = (int)jcntr;

    jfieldID thizp_cntrResetValueJFieldID = env->GetFieldID(klazz, "p_cntrResetValue", "J");
    assert( thizp_cntrResetValueJFieldID != nullptr);
    jfieldID thizcntrResetValueJFieldID = env->GetFieldID(klazz, "cntrResetValue", "I");
    assert(thizcntrResetValueJFieldID != nullptr);
    int *p_cntrResetValue = (int *)malloc(sizeof(int));
    jint jcntrResetValue=(env)->GetIntField(thiz,thizcntrResetValueJFieldID);
    *p_cntrResetValue = (int)jcntrResetValue;


    __android_log_print(ANDROID_LOG_INFO, TAG, "TTTEEEE????? %d %d\n",
                        p_imgHeight,*p_imgHeight);



    jfieldID thizp_imageAsArrayJFieldID = env->GetFieldID(klazz, "p_imageAsArray", "J");
    assert(thizp_imageAsArrayJFieldID != nullptr);
    jlong jp_imageAsArray =  (env)->GetLongField(thiz,thizp_imageAsArrayJFieldID);
    int *p_imageAsArray = (int *)jp_imageAsArray;



    getInstanceOfEnv(
            &p_modelStruct
//            , &p_numPlatforms
//            , &platforms
//            , &p_contexts
//            , &p_kernel
//            , &p_kernel1
//            , &p_kernel2
//            , &p_kernel3
//            , &p_command_queue
//            , p_local
            , &p_imageAsArray
            , p_count
//            , p_countResized
//            , p_imgWidth
//            , p_imgHeight
//            , p_imgWidthResized
//            , p_imgHeightResized
//            , p_resizedFactor
//            , p_thresholdEntireImage
//            , &p_input
//            , &p_output
//            , &p_inputHist0
//            , &p_inputHist1
//            , &p_inputHist2
//            , &p_output1
//            , &p_output3
//            , &p_changeArrayClMem
//            , &p_detectionFlag
//            , &p_detectionFlagROI
//            , &p_imageAsArray
            );


//    jfieldID thizModelStrJFieldID = env->GetFieldID(klazz, "modelStr", "J");
//    assert(thizModelStrJFieldID != nullptr);
//    jlong jModelStr =  (env)->GetLongField(thiz,thizModelStrJFieldID);
//    modelStruct *p_modelStruct = (modelStruct *)jModelStr;
//

    assert(p_modelStruct->numberOfHistograms != nullptr);
//    assert(p_contexts != nullptr);

    (env)->SetLongField(thiz,thizModelStrJFieldID,(jlong)p_modelStruct);
//    (env)->SetLongField(thiz,thizp_numPlatformsJFieldID,(jlong)p_numPlatforms);
//    (env)->SetLongField(thiz,thizplatformsJFieldID,(jlong)platforms);
//    (env)->SetLongField(thiz,thizp_contextsJFieldID,(jlong)p_contexts);
//    (env)->SetLongField(thiz,thizp_kernelJFieldID,(jlong)p_kernel);
//    (env)->SetLongField(thiz,thizp_kernel1JFieldID,(jlong)p_kernel1);
//    (env)->SetLongField(thiz,thizp_kernel2JFieldID,(jlong)p_kernel2);
//    (env)->SetLongField(thiz,thizp_kernel3JFieldID,(jlong)p_kernel3);
//    (env)->SetLongField(thiz,thizp_command_queueJFieldID,(jlong)p_command_queue);
//    (env)->SetLongField(thiz,thizlocal4PixelMaxWrokGroupSizeJFieldID,(jlong)p_local);
    (env)->SetLongField(thiz,thizp_countJFieldID,(jlong)p_count);
    (env)->SetLongField(thiz,thizp_countResizedJFieldID,(jlong)p_countResized);
    (env)->SetLongField(thiz,thizp_imgWidthJFieldID,(jlong)p_imgWidth);
    (env)->SetLongField(thiz,thizp_imgWidthResizedJFieldID,(jlong)p_imgWidthResized);
    (env)->SetLongField(thiz,thizp_imgHeightJFieldID,(jlong)p_imgHeight);
    (env)->SetLongField(thiz,thizp_imgHeightResizedJFieldID,(jlong)p_imgHeightResized);
    (env)->SetLongField(thiz,thizp_resizedFactorJFieldID,(jlong)p_resizedFactor);
    (env)->SetLongField(thiz,thizp_thresholdEntireImageJFieldID,(jlong)p_thresholdEntireImage);
    (env)->SetLongField(thiz,thizp_thresholdROIFactorJFieldID,(jlong)p_thresholdROIFactor);
//    (env)->SetLongField(thiz,thizp_inputJFieldID,(jlong)p_input);
//    (env)->SetLongField(thiz,thizp_inputHist0JFieldID,(jlong)p_inputHist0);
//    (env)->SetLongField(thiz,thizp_inputHist1JFieldID,(jlong)p_inputHist1);
//    (env)->SetLongField(thiz,thizp_inputHist2JFieldID,(jlong)p_inputHist2);
//    (env)->SetLongField(thiz,thizp_outputJFieldID,(jlong)p_output);
//    (env)->SetLongField(thiz,thizp_output1JFieldID,(jlong)p_output1);
//    (env)->SetLongField(thiz,thizp_output3JFieldID,(jlong)p_output3);
//    (env)->SetLongField(thiz,thizp_changeArrayClMemJFieldID,(jlong)p_changeArrayClMem);
//    (env)->SetLongField(thiz,thizp_detectionFlagJFieldID,(jlong)p_detectionFlag);
//    (env)->SetLongField(thiz,thizp_detectionFlagROIJFieldID,(jlong)p_detectionFlagROI);
    (env)->SetLongField(thiz,thizfaceArraySizeJFieldID,(jlong)p_faceArraySize);
    (env)->SetLongField(thiz,thizp_changesDetectionJFieldID,(jlong)p_changesDetection);
    (env)->SetLongField(thiz,thizp_changesDetectionROIJFieldID,(jlong)p_changesDetectionROI);
    (env)->SetLongField(thiz,thizchangeArrayJFieldID,(jlong)p_changeArray);
    (env)->SetLongField(thiz,thizp_cntrJFieldID,(jlong)p_cntr);
    (env)->SetLongField(thiz,thizp_cntrResetValueJFieldID,(jlong)p_cntrResetValue);
    (env)->SetLongField(thiz,thizp_imageAsArrayJFieldID,(jlong)p_imageAsArray);
//    (env)->SetLongField(thiz,thizp_roiChangesArrayJFieldID,(jlong)p_roiChangesArray);


//    __android_log_print(ANDROID_LOG_INFO, TAG, "TTTTTTT????? %d \n",
//                    p_contexts[0]);

    __android_log_print(ANDROID_LOG_INFO, TAG, "TTTEEEE????? %d %d\n",
                        p_imgHeight,*p_imgHeight);


//    jlong jlocal4PixelMaxWrokGroupSize =  (env)->GetLongField(thiz,thizlocal4PixelMaxWrokGroupSizeJFieldID);
//    size_t * p_local = (size_t *)malloc(sizeof(size_t));
//    size_t *local4PixelMaxWrokGroupSize = (size_t *)jlocal4PixelMaxWrokGroupSize;




//    int* p_count = (int *)malloc(sizeof(int));
//    int* p_countResized1 = (int *)malloc(sizeof(int));
//    int* p_imgWidth = (int *)malloc(sizeof(int));
//    int* p_resizedWidth = (int *)malloc(sizeof(int));
//    int* p_imgHeight = (int *)malloc(sizeof(int));
//    int* p_resizedHeight = (int *)malloc(sizeof(int));
//    int* p_resizedFactor = (int *)malloc(sizeof(int));
//    int* p_thresholdEntireImage = (int *)malloc(sizeof(int));

}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_AndroidOpenCvOpenClNativeExample_NAFFD_processFrameRunJNI(JNIEnv *env,
                                                                           jobject thiz,
                                                                           jlong matAdrr) {
    cv::Mat &mat = *(cv::Mat *) matAdrr;

    assert((env) != nullptr);
    jclass klazz = (env)->GetObjectClass(thiz);
    assert((klazz) != nullptr);

    jfieldID thizchangeArrayJFieldID = env->GetFieldID(klazz, "changeArray", "J");
    assert(thizchangeArrayJFieldID != nullptr);
    jlong jp_changeArray =  (env)->GetLongField(thiz,thizchangeArrayJFieldID);
    int *p_changeArray = (int*)jp_changeArray;

    jfieldID thizp_cntrJFieldID = env->GetFieldID(klazz, "p_cntr", "J");
    assert( thizp_cntrJFieldID != nullptr);
    jlong jp_cntr=(env)->GetLongField(thiz,thizp_cntrJFieldID);
    int *p_cntr = (int*)jp_cntr;

    jfieldID thizp_cntrResetValueJFieldID = env->GetFieldID(klazz, "p_cntrResetValue", "J");
    assert( thizp_cntrResetValueJFieldID != nullptr);
    jlong jp_cntrResetValue=(env)->GetLongField(thiz,thizp_cntrResetValueJFieldID);
    int *p_cntrResetValue = (int*)jp_cntrResetValue;

    jfieldID thizp_roiChangesArrayJFieldID = env->GetFieldID(klazz, "p_roiChangesArray", "J");
    assert( thizp_roiChangesArrayJFieldID != nullptr);
    jlong jp_roiChangesArray=(env)->GetLongField(thiz,thizp_roiChangesArrayJFieldID);
    int *p_roiChangesArray = (int*)jp_roiChangesArray;

    jfieldID thizp_changesDetectionJFieldID = env->GetFieldID(klazz, "p_changesDetection", "J");
    assert(thizp_changesDetectionJFieldID != nullptr);
    jlong jp_changesDetection = (env)->GetLongField(thiz,thizp_changesDetectionJFieldID);
    int *p_changesDetection = (int*)jp_changesDetection;

    jfieldID thizp_changesDetectionROIJFieldID = env->GetFieldID(klazz, "p_changesDetectionROI", "J");
    assert(thizp_changesDetectionROIJFieldID != nullptr);
    jlong jp_changesDetectionROI = (env)->GetLongField(thiz,thizp_changesDetectionROIJFieldID);
    int *p_changesDetectionROI = (int*)jp_changesDetectionROI;

    jfieldID thizfaceArraySizeJFieldID = env->GetFieldID(klazz, "facesArraySize", "J");
    assert(thizfaceArraySizeJFieldID != nullptr);
    jlong jfaceArraySize =  (env)->GetLongField(thiz,thizfaceArraySizeJFieldID);
    int* p_faceArraySize = (int *)jfaceArraySize;

    jfieldID thizp_thresholdEntireImageJFieldID = env->GetFieldID(klazz, "p_thresholdEntireImage", "J");
    assert(thizp_thresholdEntireImageJFieldID != nullptr);
    jlong jp_thresholdEntireImage =  (env)->GetLongField(thiz,thizp_thresholdEntireImageJFieldID);
    int* p_thresholdEntireImage = (int *)jp_thresholdEntireImage;

    jfieldID thizp_thresholdROIFactorJFieldID = env->GetFieldID(klazz, "p_thresholdROIFactor", "J");
    assert(thizp_thresholdROIFactorJFieldID != nullptr);
    jlong jp_thresholdROIFactor =  (env)->GetLongField(thiz,thizp_thresholdROIFactorJFieldID);
    double* p_thresholdROIFactor = (double *)jp_thresholdROIFactor;

    jfieldID thizp_facesArrayJFieldID = env->GetFieldID(klazz, "p_facesArray", "J");
    assert(thizp_facesArrayJFieldID != nullptr);
    jlong jp_facesArray =  (env)->GetLongField(thiz,thizp_facesArrayJFieldID);
    int* p_facesArray = (int *)jp_facesArray;

    jfieldID thizp_facesArraySizeJFieldID = env->GetFieldID(klazz, "facesArraySize", "J");
    assert(thizp_facesArraySizeJFieldID != nullptr);
    jlong jp_facesArraySize =  (env)->GetLongField(thiz,thizp_facesArraySizeJFieldID);
    int* p_facesArraySize = (int *)jp_facesArraySize;

    jfieldID thizModelStrJFieldID = env->GetFieldID(klazz, "modelStr", "J");
    assert(thizModelStrJFieldID != nullptr);
    jlong jModelStr =  (env)->GetLongField(thiz,thizModelStrJFieldID);
    modelStruct *p_modelStruct = (modelStruct *)jModelStr;

//    jfieldID thizp_contextsJFieldID = env->GetFieldID(klazz, "p_contexts", "J");
//    assert(thizp_contextsJFieldID != nullptr);
//    jlong jp_contexts =  (env)->GetLongField(thiz,thizp_contextsJFieldID);
//    cl_context *p_contexts = (cl_context *)jp_contexts;
//
//    jfieldID thizp_kernelJFieldID = env->GetFieldID(klazz, "p_kernel", "J");
//    assert(thizp_kernelJFieldID != nullptr);
//    jlong jp_kernel =  (env)->GetLongField(thiz,thizp_kernelJFieldID);
//    cl_kernel *p_kernel = (cl_kernel *)jp_kernel;
//
//    jfieldID thizp_kernel1JFieldID = env->GetFieldID(klazz, "p_kernel1", "J");
//    assert(thizp_kernel1JFieldID != nullptr);
//    jlong jp_kernel1 =  (env)->GetLongField(thiz,thizp_kernel1JFieldID);
//    cl_kernel *p_kernel1 = (cl_kernel *)jp_kernel1;
//
//    jfieldID thizp_kernel2JFieldID = env->GetFieldID(klazz, "p_kernel2", "J");
//    assert(thizp_kernel2JFieldID != nullptr);
//    jlong jp_kernel2 =  (env)->GetLongField(thiz,thizp_kernel2JFieldID);
//    cl_kernel *p_kernel2 = (cl_kernel *)jp_kernel2;

//    jfieldID thizp_kernel3JFieldID = env->GetFieldID(klazz, "p_kernel3", "J");
//    assert(thizp_kernel3JFieldID != nullptr);
//    jlong jp_kernel3 =  (env)->GetLongField(thiz,thizp_kernel3JFieldID);
//    cl_kernel *p_kernel3 = (cl_kernel *)jp_kernel3;
//
//    jfieldID thizp_command_queueJFieldID = env->GetFieldID(klazz, "p_commandsArray", "J");
//    assert(thizp_command_queueJFieldID != nullptr);
//    jlong jp_command_queue =  (env)->GetLongField(thiz,thizp_command_queueJFieldID);
//    cl_command_queue **p_command_queue = (cl_command_queue **)jp_command_queue;

//    jfieldID thizlocal4PixelMaxWrokGroupSizeJFieldID = env->GetFieldID(klazz, "local4PixelMaxWrokGroupSize", "J");
//    assert(thizlocal4PixelMaxWrokGroupSizeJFieldID != nullptr);
//    jlong jp_local4PixelMaxWrokGroupSize =  (env)->GetLongField(thiz,thizlocal4PixelMaxWrokGroupSizeJFieldID);
//    size_t * p_local4PixelMaxWrokGroupSize = (size_t *) jp_local4PixelMaxWrokGroupSize;

    jfieldID thizp_countJFieldID = env->GetFieldID(klazz, "p_count", "J");
    assert( thizp_countJFieldID != nullptr);
    jlong jp_count=(env)->GetLongField(thiz,thizp_countJFieldID);
    int *p_count = (int*)jp_count;

    jfieldID thizp_countResizedJFieldID = env->GetFieldID(klazz, "p_countResized", "J");
    assert( thizp_countResizedJFieldID != nullptr);
    jlong jp_countResized=(env)->GetLongField(thiz,thizp_countResizedJFieldID);
    int *p_countResized = (int*)jp_countResized;

    jfieldID thizp_imgWidthJFieldID = env->GetFieldID(klazz, "p_imgWidth", "J");
    assert( thizp_imgWidthJFieldID != nullptr);
    jlong jp_imgWidth=(env)->GetLongField(thiz,thizp_imgWidthJFieldID);
    int *p_imgWidth = (int*)jp_imgWidth;

    jfieldID thizp_imgWidthResizedJFieldID = env->GetFieldID(klazz, "p_imgWidthResized", "J");
    assert( thizp_imgWidthResizedJFieldID != nullptr);
    jlong jp_imgWidthResized=(env)->GetLongField(thiz,thizp_imgWidthResizedJFieldID);
    int *p_imgWidthResized = (int*)jp_imgWidthResized;

    jfieldID thizp_imgHeightJFieldID = env->GetFieldID(klazz, "p_imgHeight", "J");
    assert( thizp_imgHeightJFieldID != nullptr);
    jlong jp_imgHeight=(env)->GetLongField(thiz,thizp_imgHeightJFieldID);
    int *p_imgHeight = (int*)jp_imgHeight;

    jfieldID thizp_imgHeightResizedJFieldID = env->GetFieldID(klazz, "p_imgHeightResized", "J");
    assert( thizp_imgHeightResizedJFieldID != nullptr);
    jlong jp_imgHeightResized=(env)->GetLongField(thiz,thizp_imgHeightResizedJFieldID);
    int *p_imgHeightResized = (int*)jp_imgHeightResized;

    jfieldID thizp_resizedFactorJFieldID = env->GetFieldID(klazz, "p_resizedFactor", "J");
    assert( thizp_resizedFactorJFieldID != nullptr);
    jlong jp_resizedFactor=(env)->GetLongField(thiz,thizp_resizedFactorJFieldID);
    int *p_resizedFactor = (int*)jp_resizedFactor;

//    jfieldID thizp_inputJFieldID = env->GetFieldID(klazz, "p_input", "J");
//    assert(thizp_inputJFieldID != nullptr);
//    jlong jp_input =  (env)->GetLongField(thiz,thizp_inputJFieldID);
//    cl_mem *p_input = (cl_mem *)jp_input;
//
//    jfieldID thizp_output1JFieldID = env->GetFieldID(klazz, "p_output1", "J");
//    assert(thizp_output1JFieldID != nullptr);
//    jlong jp_output1=  (env)->GetLongField(thiz,thizp_output1JFieldID);
//    cl_mem *p_output1 = (cl_mem *)jp_output1;
//
//    jfieldID thizp_output2JFieldID = env->GetFieldID(klazz, "p_output2", "J");
//    assert(thizp_output2JFieldID != nullptr);
//    jlong jp_output2=  (env)->GetLongField(thiz,thizp_output2JFieldID);
//    cl_mem *p_output2 = (cl_mem *)jp_output2;
//
//    jfieldID thizp_changeArrayClMemJFieldID = env->GetFieldID(klazz, "p_changeArrayClMem", "J");
//    assert(thizp_changeArrayClMemJFieldID != nullptr);
//    jlong jp_changeArrayClMem =  (env)->GetLongField(thiz,thizp_changeArrayClMemJFieldID);
//    cl_mem *p_changeArrayClMem = (cl_mem *)jp_changeArrayClMem;
//
//    jfieldID thizp_detectionFlagJFieldID = env->GetFieldID(klazz, "p_detectionFlag", "J");
//    assert(thizp_detectionFlagJFieldID != nullptr);
//    jlong jp_detectionFlag =  (env)->GetLongField(thiz,thizp_detectionFlagJFieldID);
//    cl_mem *p_detectionFlag = (cl_mem *)jp_detectionFlag;

//    jfieldID thizp_detectionFlagROIJFieldID = env->GetFieldID(klazz, "p_detectionFlagROI", "J");
//    assert(thizp_detectionFlagROIJFieldID != nullptr);
//    jlong jp_detectionFlagROI =  (env)->GetLongField(thiz,thizp_detectionFlagROIJFieldID);
//    cl_mem *p_detectionFlagROI = (cl_mem *)jp_detectionFlagROI;
//
//    jfieldID thizp_facesArrayMemJFieldID = env->GetFieldID(klazz, "p_facesArrayMem", "J");
//    assert(thizp_facesArrayMemJFieldID != nullptr);
//    jlong jp_facesArrayMem =  (env)->GetLongField(thiz,thizp_facesArrayMemJFieldID);
//    cl_mem *p_facesArrayMem = (cl_mem *)jp_facesArrayMem;
//
//    jfieldID thizp_changeArrayROIClMemJFieldID = env->GetFieldID(klazz, "p_changeArrayROIClMem", "J");
//    assert(thizp_changeArrayROIClMemJFieldID != nullptr);
//    jlong jp_changeArrayROIClMem =  (env)->GetLongField(thiz,thizp_changeArrayROIClMemJFieldID);
//    cl_mem *p_changeArrayROIClMem = (cl_mem *)jp_changeArrayROIClMem;


    jfieldID thizp_imageAsArrayJFieldID = env->GetFieldID(klazz, "p_imageAsArray", "J");
    assert(thizp_imageAsArrayJFieldID != nullptr);
    jlong jp_imageAsArray =  (env)->GetLongField(thiz,thizp_imageAsArrayJFieldID);
    int *p_imageAsArray = (int *)jp_imageAsArray;

//    __android_log_print(ANDROID_LOG_INFO, TAG, "TTTTTTT????? %d \n",
//                    p_contexts[0]);

//    __android_log_print(ANDROID_LOG_INFO, TAG, "TTTEEEE????? %d %d\n",
//                        p_imgHeight,*p_imgHeight);

    frameProcess(
            mat
            ,p_cntr
            ,p_cntrResetValue
            ,p_changeArray
            ,&p_roiChangesArray
            ,p_changesDetection
			,p_changesDetectionROI
			,p_facesArraySize
			,p_thresholdROIFactor
			,&p_facesArray
			,&p_modelStruct
//			,&p_contexts
//			,&p_kernel
//			,&p_kernel1
//			,&p_kernel2
//			,&p_kernel3
//			,&p_command_queue
//			,1
//			, p_local4PixelMaxWrokGroupSize
            , p_count
            , p_countResized
            , p_imgWidth
            , p_imgHeight
            , p_imgWidthResized
            , p_imgHeightResized
            , p_resizedFactor
            , p_thresholdEntireImage
//			,&p_input
//			,&p_output1
//			,&p_output2
//			,&p_changeArrayClMem
//			,&p_detectionFlag
//			,&p_detectionFlagROI
//			,&p_facesArrayMem
//			,&p_changeArrayROIClMem
			,&p_imageAsArray
            );

    //save ouput2 facesArraymem p_roiChangesArray,  p_changeArrayROIClMem
//    (env)->SetLongField(thiz,thizp_output2JFieldID,(jlong)p_output2);
    (env)->SetLongField(thiz,thizp_facesArrayJFieldID,(jlong)p_facesArray);
//    (env)->SetLongField(thiz,thizp_facesArrayMemJFieldID,(jlong)p_facesArrayMem);
    (env)->SetLongField(thiz,thizp_roiChangesArrayJFieldID,(jlong)p_roiChangesArray);
//    (env)->SetLongField(thiz,thizp_changeArrayROIClMemJFieldID,(jlong)p_changeArrayROIClMem);



}