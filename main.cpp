#include <iostream>
#include <string.h>
#include <portaudio.h>


int main() {
    PaError err;
    err = Pa_Initialize();
    printf("%s \n", Pa_GetErrorText(err));


    PaDeviceIndex ndev = Pa_GetDeviceCount();
    PaDeviceIndex j =0;
    const PaDeviceInfo *info;

    int i=0;

    for(i=0; i<ndev; i++){
        info = Pa_GetDeviceInfo((PaDeviceIndex) i);
        if(info->maxOutputChannels > 0) printf("output device: ");
        if (info->maxInputChannels > 0) printf("input device: ");
        printf("%d: %s\n", i, info->name);
    }


    int devin=16;
    int devout=11;
    PaStreamParameters inparam, outparam;
    memset(&inparam, 0, sizeof(PaStreamParameters));
    inparam.device = devin;
    inparam.channelCount = 1;
    inparam.sampleFormat = paFloat32;

    memset(&outparam, 0, sizeof(PaStreamParameters));
    outparam.device = devout;
    outparam.channelCount = 1;
    outparam.sampleFormat = paFloat32;


    return 0;
}
