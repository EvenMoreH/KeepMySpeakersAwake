# KeepMySpeakersAwake
Simple console-less C app that outputs a beep in ~11-13 minute intervals so your speakers won't go to sleep.

I have decided to write an app that keeps speakers active, preventing them from moving to sleep state.
Personally I have a Sharp speakers hooked up to my PC and unfortunately there is no way to disable sleep function for this particular model.
I literally taught myself enough C to compile this app.

How it works?
It plays a looped bass sound of 160Hz for 21 milliseconds through PCs currently set output device. Loop is put to sleep for a random amount of time between ~11.5 and 13.5 minutes and beeps again.

Why this amount of Hz? This amount of playtime? Only one beep?
Well, I tried different combinations and for my speakers one beep was enough however everything shorter than 21ms was not being registered. Why 160Hz tho, well for values below again speakers were not registering it properly.

How do I run it?
I put it in my windows startup folder so it runs automatically each time I turn on the the PC.

How do I stop it?
1. Open Task Manager and kill the process.
2. Open CMD and run following command: taskkill /f /im keepMySpeakersAwake.exe
3. My personal favorite, create a batch file with above command and keep a nice shortcut with pretty icon on the desktop whenever you want to stop the app. 
   (I've included pre-made batch in repository)
