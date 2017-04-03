Development of this ANE is on hold until Adobe supports 64-bit-only ANEs
========================================================================
> The `myo.framework` is now only available in 64-bit and ANEs are currently required to be compiled for both 32- and 64-bit.

[<img src="http://logotype.github.io/LeapMotionAS3Docs/examples/myo/logo_as3.png">](https://github.com/logotype/MyoAS3)

This is the AS3 framework for working with Thalmic Labs Myo.

The Myo armband measures the electrical activity from your muscles to detect what gesture your hand is making. It also senses all of the motions and rotations of your hand and forearm.

[thalmic.com](http://www.thalmic.com)

Quick start
-----------

Clone the repo, `git clone git://github.com/logotype/MyoAS3.git`.

Features
--------
<img src="http://logotype.github.io/LeapMotionAS3Docs/examples/myo/myoas3-stack.png">
+ Clean, lightweight and documented code
+ Same structure as official API
+ Uses AIR 16/ASC 2.0 compiler features (add the `-inline` and `-swf-version=27` compiler arguments)
+ No external dependencies
+ AIR Native Extension (ANE) which directly interfaces with the C++ library (Mac OSX and Windows)
+ Compatible with Mac OSX (coming soon: Windows, iOS (iPad/iPhone/etc) and Android)

AIR Native Extension
--------------------

You can use this library on both web and AIR projects. If you are using it on an AIR for Desktop project, you can take advantage of the AIR Native Extension.

[Download the ANE-file](https://github.com/logotype/MyoAS3/blob/master/bin/MyoAS3.ane?raw=true) and place it somewhere in your project (preferably in the directory where you would put your swc files). Link the ANE file to your project:

####Flash Builder 4.7


1. Right click on your AIR for desktop project and choose properties.
2. Select Actionscript build path > Library path and click on Add SWC… Select the ANE file you just downloaded.
3. In that same window, choose Native Extensions and click on Add ANE… Select that same ANE file.
4. Select Actionscript Build Packaging > Native extensions. Check the checkbox next to the native extension. Ignore the warning that says the extension isn't used.

####Flash CC/Flash CS6


1. Select File > Actionscript settings.
2. On the Library Path tab, click on the "Browse to a Native Extension (ANE)" button (button to the right of the SWC button).
3. Choose the ANE file you just downloaded.

####IntelliJ IDEA


1. Right-click on your module and choose "Open Module Settings".
2. Select the build configuration for your Module and open the Dependencies tab.
3. Click on the plus (+) button on the bottom of that window and choose "New Library…".
4. Choose the ANE file you just downloaded.

Authors
-------

**Victor Norgren**

+ http://twitter.com/logotype
+ https://github.com/logotype
+ https://logotype.se


Copyright and license
---------------------

Copyright © 2014 logotype

Author: Victor Norgren

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to
deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:  The above copyright
notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.

--------------------------
Built with IntelliJ IDEA Open Source License

<a href="https://www.jetbrains.com/buy/opensource/"><img src="https://s3-ap-southeast-1.amazonaws.com/www.logotype.se/assets/logo-text.svg" width="200"></a>

The people at JetBrains supports the Open Source community by offering free licenses. Check out <a href="https://www.jetbrains.com/buy/opensource/">JetBrains Open Source</a> to apply for your project. Thank you!
