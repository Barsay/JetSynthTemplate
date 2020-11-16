# JETSON NANO - PORTAUDIO TEMPLATE

My template for audio programming on a nVIDIA Jetson Nano using PortAudio. 
Uses CMAKE.
Created for myself in order to keep record of an hour or so of research. But suggestions are welcome! 
notice: 

Should works on C programs as well just create a new <code>main.c</code>. Works perfectly on CLion.
## Installantion and dependencies check
Disclaimer: the workflow could be messy, redundant or not efficient... But it works on a Jetson Nano and it should work anywhere else. So it's ok for now.
### ALSA
  1. Check if ALSA is installed on your system. If it isn't run <code>sudo apt install alsa-utils</code>
  2. Check if ALSA works typing <code>aplay -vv somefile.wav </code>
  Alsa Documentation for troubleshooting: <link>https://www.alsa-project.org/wiki/SoundcardTesting#Rule_of_Thumb</link>
  General Alsa documentation: <link>https://www.alsa-project.org/wiki/Documentation</link>
 ### PortAudio
  1. clone portAudio from <link>https://github.com/PortAudio/portaudio</link> into a folder
  2. open the cloned folder, type <code>./configure/code>
  3. type <code>cd build</code> (if build doesnt exist, type <code>mkdir build</code> )
  4. type <code>cmake .. -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=/usr/lib/portAudio</code>.
  5. type <code>sudo make </code> then <code> make install </code> 
  Documentation for troubleshooting: <link>http://portaudio.com/docs/v19-doxydocs/compile_cmake.html</link>, <link>http://portaudio.com/docs/v19-doxydocs/compile_linux.html</link>
  General portaudio documentation  <link>http://portaudio.com/docs/v19-doxydocs/index.html</link>
  
## USE IT:
  1. Clone this repo
  2. On line 2 in CMakeLists.txt change <code>-insert projectname here</code> with the name of your project
  (otherise your project will be named "<code>-insert projectname here</code>", lol)
