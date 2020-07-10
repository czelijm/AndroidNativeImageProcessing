package com.example.AndroidOpenCvOpenClNativeExample;

public class NAFFD {
    private int height;
    private int width;
    private int imageChannels=3;
    private int resizedFactor;
    private int thresholdEntireImage;
    private double thresholdROIFactor;
    private int cntr;
    private int cntrResetValue;

    private int count;
    private int countResized;
    private int imgWidthResized;
    private int imgHeightResized;
    private int changeDetection=1;
    private int changeDetectionROI=1;

    private long p_imageChannels;
    private long p_resizedFactor;
    private long p_imgWidthResized;
    private long p_imgHeightResized;
    private long p_thresholdEntireImage;
    private long p_thresholdROIFactor;


    private long modelStr;

	private long p_numPlatforms;
	private long platforms;
	private long p_contexts;
	private long p_kernel;
	private long p_kernel1;
	private long p_kernel2;
	private long p_kernel3;
	private long p_commandsArray;
	private long local4PixelMaxWrokGroupSize;
//	private long p_thresholdEntireImage;
	private long p_input;
	private long p_output;
	private long p_inputHist0;
	private long p_inputHist1;
	private long p_inputHist2;
	private long p_output1;
    private long p_output2;
	private long p_output3;
	private long p_changeArrayClMem;
	private long p_detectionFlag;
	private long p_detectionFlagROI;

    private long  frame;
    private long  p_count;
    private long  p_countResized;
    private long  p_cntr;
	private long  p_cntrResetValue;
	private long  changeArray;
	private long  p_roiChangesArray;
	private long  p_changesDetection;
	private long  p_changesDetectionROI;
	private long  facesArraySize;
//	private long  p_thresholdROIFactor;
	private long  p_facesArray;
	private long p_facesArrayMem;
	private long p_changeArrayROIClMem;
	private int numPlatforms;
    private long p_imgWidth;
    private long p_imgHeight;
    private long p_imageAsArray;


    public NAFFD(int height, int width, int imageChannels, int resizedFactor, double thresholdEntireImage, double thresholdROIFactor,int cntrResetValue) {
        this.height = height;
        this.width = width;
        this.imageChannels = imageChannels;
        this.resizedFactor = resizedFactor;
        this.imgHeightResized =this.height/this.resizedFactor;
        this.imgWidthResized =this.width/this.resizedFactor;
        this.count=this.height*this.width*this.imageChannels;
        this.countResized=this.imgHeightResized *this.imgWidthResized *this.imageChannels;
        this.thresholdEntireImage=(int)(this.countResized*thresholdEntireImage*255);
        this.thresholdROIFactor=thresholdROIFactor;
        this.cntrResetValue=cntrResetValue;
        this.cntr=cntrResetValue;
//        this.parametersUpdate();
        this.restParametersInit();
    }

    private void parametersUpdate(){
        this.imgHeightResized =this.height/this.resizedFactor;
        this.imgWidthResized =this.width/this.resizedFactor;
        this.count=this.height*this.width*this.imageChannels;
        this.countResized=this.imgHeightResized *this.imgWidthResized *this.imageChannels;
        this.thresholdEntireImage=(int)(this.countResized*thresholdEntireImage*255);
    }

    private void restParametersInit(){
//        this.count=0;
//        this.countResized=0;
        this.p_imageChannels = 0;
        this.p_resizedFactor = 0;
        this.p_imgWidth=0;
        this.p_imgHeight=0;
        this.p_imgWidthResized = 0;
        this.p_imgHeightResized = 0;
        this.modelStr = 0;
        this.p_numPlatforms = 0;
        this.platforms = 0;
        this.p_contexts = 0;
        this.p_kernel = 0;
        this.p_kernel1 = 0;
        this.p_kernel2 = 0;
        this.p_kernel3 = 0;
        this.p_commandsArray = 0;
        this.local4PixelMaxWrokGroupSize = 0;
        this.p_thresholdEntireImage = 0;
        this.p_input = 0;
        this.p_output = 0;
        this.p_inputHist0 = 0;
        this.p_inputHist1 = 0;
        this.p_inputHist2 = 0;
        this.p_output1 = 0;
        this.p_output2 = 0;
        this.p_output3 = 0;
        this.p_changeArrayClMem = 0;
        this.p_detectionFlag = 0;
        this.p_detectionFlagROI = 0;
        this.frame = 0;
        this.p_cntr = 0;
        this.p_cntrResetValue = 0;
        this.changeArray = 0;
        this.p_roiChangesArray = 0;
        this.p_changesDetection = 0;
        this.p_changesDetectionROI = 0;
        this.facesArraySize = 0;
        this.p_thresholdROIFactor = 0;
        this.p_facesArray = 0;
        this.p_facesArrayMem = 0;
        this.p_changeArrayROIClMem = 0;
        this.p_imageAsArray = 0;

        this.numPlatforms = 1;
        this.changeDetection=1;
        this.changeDetectionROI=1;

    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public int getImageChannels() {
        return imageChannels;
    }

    public void setImageChannels(int imageChannels) {
        this.imageChannels = imageChannels;
    }

    public int getResizedFactor() {
        return resizedFactor;
    }

    public void setResizedFactor(int resizedFactor) {
        this.resizedFactor = resizedFactor;
    }

    public long getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public long getCountResized() {
        return countResized;
    }

    public void setCountResized(int countResized) {
        this.countResized = countResized;
    }

    public long getImgWidthResized() {
        return imgWidthResized;
    }

    public void setImgWidthResized(int imgWidthResized) {
        this.imgWidthResized = imgWidthResized;
    }

    public long getImgHeightResized() {
        return imgHeightResized;
    }

    public void setImgHeightResized(int imgHeightResized) {
        this.imgHeightResized = imgHeightResized;
    }

    public long getPointerModel() {
        return modelStr;
    }

    public void setModelStr(long modelStr) {
        this.modelStr = modelStr;
    }

    private native void adaptiveThresholdFromJNI(long mat);
//    private native void getInstanceOfEnvJNI(int a);
//    private native void getInstanceOfEnvJNI();
    private native void processFrameRunJNI(long matAdr);
    private native void getInstanceOfEnvRunJNI();
//    getInstanceOfEnvRunJNI

    public void getInstanceOfEnvRun(){
//        System.out.println("LALALALLALAL"+this.getResizedFactor());
//        getInstanceOfEnvJNI(this.resizedFactor);
        getInstanceOfEnvRunJNI();
    }

    public void processFrameRun(long matAdr){
        processFrameRunJNI(matAdr);
    }

}
