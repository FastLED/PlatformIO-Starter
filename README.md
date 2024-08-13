# PlatformIO-Starter

Basic starter project for developing FastLED applications in PlatformIO. It's also backward compatible with Arduino IDE.

# Why?

PlatformIO is generally viewed as a **much** better coding exprience that Arduino IDE. It's also extremely easy to setup and start using. Typically users will start out with the Arduino IDE then graduate to PlatformIO and never look back. The main benefits come not from PlatformIO but actually using VSCode: including AutoComplete and CoPilot which will 10x your ability to write code (no joke).

PlatformIO is a better package manager than the one ArduinoIDE uses primarily because your depedencies are defined with the project repo instead of globally. This means you can hand off you code repo to someone else and they can just fire it up in platformio and all dependencies will auto-magically be installed and they can start running your project.

Everything you'd want to do in Arduino IDE can be done with VSCode + PlatformIO. Keep that in mind. If you don't like platformIO you can still use the ArduinoIDE. This repo has been designed to allow both.

# Quick Start

## One time installation: Install VSCode + PlatformIO

  * Download and install VSCode
  * Open up VSCode and install the platformio extension
    * On the left hand side toolbar you'll see this icon, click it:
      * <img width="53" alt="image" src="https://github.com/user-attachments/assets/d0f118ad-8f1f-42a5-ade6-d1d79dd83ca4">
    * Search for extension "PlatformIO":
      * <img width="246" alt="image" src="https://github.com/user-attachments/assets/a4805786-4c42-4859-9761-6af14bacd9c3">
    * Then install it.

## Download this repo or `git clone` it

  * Download
    * Use this link: https://github.com/FastLED/PlatformIO-Starter/archive/refs/heads/main.zip

  * -or- `git clone` it
    * `git clone https://github.com/FastLED/PlatformIO-Starter`
   
  * Now open up the repo directory in `VSCode`.
   

  * Now all the dependencies to will be automatically installed and you can hit the compile or upload button
    * Compile: Looks like a "checkmark" icon at the bottom toolbar of VSCode.
    * Compile and Upload: Looks like a "right arrow" at the bottom toolbar of VSCode, right to the right of the "compile" button.
    * Example:
      * <img width="223" alt="image" src="https://github.com/user-attachments/assets/81c94d7b-cc50-46fd-ad7d-ced91c254d36">
    * The "Serial Monitor" (so you can see Serial.print) is located with this button at the very right: <img width="147" alt="image" src="https://github.com/user-attachments/assets/ed57b60d-a5b8-4dee-8b45-2a7f5616004c">
  * Looking to go even further? Checkout the full platformio tutorial here: https://docs.platformio.org/en/latest/integration/ide/vscode.html#quick-start



## Using a board other than Arduino UNO

  1. Open up platformio.ini at the root of this repo.
  2. Modify the `board = uno` part with your board.
  3. Everything will auto magically update and you can compile/upload and it should just work.

You can also look at the platforms/ folder [here](https://github.com/FastLED/PlatformIO-Starter/tree/main/platforms) for platformio ini files that you can use to get the main sketch running for your specific board type.

## Stuck? Use ChatGPT or Claude

It's worth noting that the LLM Chatbots have all been trained on platformio's `platformio.ini` file. Simply copy and paste your `platformio.ini` file into one of the chat bots then ask it to make modifiations to run your board and it will probably work the first time.

## Install Package Libraries

As far as we are aware, all the packages that work for ArduinoIDE also work for platformio. Just grab the name of the package you are interested (for example, FastLED) and put it at the `lib_deps` section of the platformio.in file.

Example:

```
lib_deps =
	FastLED
```

## Backwards compatible with Arduino IDE?

Yes. This repo has been specially constructed to be backwards compatible with the Arduino IDE. Just open up the repo with Arduino IDE and hit compile (after selecting the proper global packages and board type)

Make sure the sketch file is named the same as it's parent directory. For example the parent directory in this repo is `PlatformIO-Starter` and therefore the ino file is also called `PlatformIO-Starter.ino`.

# Why PlatformIO over Arduino IDE?

In a nutshell you will write code 10x faster with platformio because of VSCode's advanced coding tools. Once you get one project in PlatformIO you'll never want to go back to the Arduino IDE.


### Advanced AutoComplete + CoPillot

PlatformIO relies on VSCode which has far more advanced
autocompletion tools for writing code. For example you
can jump to a function definition with a right click. This works not only for your own code but the libraries that you use. For example you can jump to FastLED's implementation of `FastLED.show()` with a right click and
see what's going on.

CoPilot is an amazing tool that will 10x your coding. No JOKE! Since VSCode as first class support of CoPilot, you can now use this in your Arduino Projects here.

### Not necessary to select the port

Arduino IDE wants you to select the port. PlatformIO uses magic to find this for you.

### Your project contains your board information

With Arduino IDE you have to set your board information. If you hand off your sketch to someone else then you have to include instructions on which board they need to use within the Arduino IDE. With platformIO you can set the board for your project. You can also highly customize things like the uploader or monitoring speed at the project level.

### Debugging is MUCH easier!

Got a problem with a library package? Right click one of the symbols and VSCode will open the file that contains that symbol. Arduino IDE makes you discover where this file is manually.

### Project Dependencies: Local By Default instead of Global by Default!

In the Arduino IDE you install dependencies (like FastLED) at the Global level. If you downgrade one of your dependencies then EVERY sketch also get's downgraded. You simply cannot have local packages unless you copy and paste the entire code base into your sketches src/ directory.

However, platformio takes a different approach, every dependencies is local to your sketch folder in the .pio directory.

This means that all project depedencies for a specific sketch repo will stay with that sketch and won't affect anything else.

A real world example of how useful it is can be illustrated with the recent Arduion 2.3.1 upgrade, which forced the esp32 idf 5.1 library onto all Arduino users. This broke *every single* FastLED user in the Arduino IDE universe that was compiling FastLED for one of the esp32-s3 flavors of boards. To fix this you had to downgrade the package dependency at the global level. However with platform io you can happily pin your depenencies to versions you know works. If you give your repo to someone else, then you can be pretty certain it will work for them to.
