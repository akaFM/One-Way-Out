# "One Way Out" - A Text-Based RPG

 > *Authors*
 > ----------
>  [Avo Karamusyan](https://github.com/akaFM) - akara044
> 
>  [Vincent Tang](https://github.com/vtang020) - vtang020
> 
>  [Andrew Pham](https://github.com/afCS100) - apham184
> 
>  [Benjamin Nguyen](https://github.com/Bnguy777) - bnguy280
>
>  [Thien Pham](https://github.com/apeisd) - tpham108
> 

## Project Description

> ### *Why is this project important to us?*
> In our coursework up until this point, we've used coding solely for academic purposes. But we've perservered in using it because we are aware that it is an extremely valuable real-world skill and have been anticipating the creation of something more useful. Whether it is for designing webpages or constructing major entertainment titles, coding is used around the world for "real" purposes. "One Way Out" represents the first time that we will use our accumulated skills for something more practical- something that others, especially those who are entirely familiar with computer programming, can enjoy in the real world. This project gives us a chance to present our collective knowledge in the form of something almost everyone can enjoy- a simple computer game.
>
> ### *What languages/tools/technologies will we use?*
> "One Way Out" will be programmed entirely in C++, using Visual Studio Code for organization and GitHub for collaboration. It won't have a GUI, but will instead rely on user interaction through the console. Since the game is text-based, we have to put in quite a lot of extra effort for immersion purposes, so one of our big objectives is to push the limits of how detailed and interactive a console-based game can get. Since we are exclusively using C++, but still want to show off what we've learned so far, we'll be using a wide variety of techniques for the purpose of creating and maintaining diverse/practical code. Some of these techniques will include inheritance, polymorphism, 2D arrays, and a particular emphasis on object-oriented programming.
>
> ### *What will the input/output of our program be?*
> As stated earlier, "One Way Out" will be a fully text-based RPG. **Input will be taken in the form of commands and specifications, typed out by the user in the console.** This input will be modified and analyzed with respect to the context of the user's current position in the game, so that we can calculate an adequate **text output through the console**. Text prompts will be detailed and push the user in the right direction, but without hindering the extent to which the game is challenging. In our text outputs, we aim to create an appropriate balance between immersion and fun, and in order to accomplish this, our prompts need to be well thought-out and tested (preferrably by people outside of the development team). It is possible that some factors of the game (such as the player's health points, attack power, etc) will be determined by a difficulty chosen by the user, which means that user input has a direct impact on how these factors are computed and displayed.
>
> ### *What features will our program provide?*
>  * A difficulty setting which allows for user input to directly influence computations made throughout the game (maybe speedrun mode?)
>  * A detailed and thought-out storyline with immersive and informational text outputs
>  * A "stats" system, in which the player can "level up" the character's HP, attack power, and more
>  * A weapons system, in which interacting with different weapons produces different results/outputs (class inheritance)
>  * An array of enemies, which will potentially behave differently altogether, and possibly be in randomized locations
>  * A predetermined map with boundaries, maintained using a 2D array (map can potentially shift like a labyrinth, which would require some sort of algorithm)
>  * A battling system (we don't know much about details, but there needs to be some sort of incentive for the player to stay alert)
>  * An inventory system, entailing objects like keys, which allow for access to certain features/items/locations, and temporarily bar access from others. Also allows for consumables, which will have an effect on the stats system, and so on.
>  * ...and all of the above will likely be very thoroughly bugtested by people outside of the development team, so that we can get a good idea of what is expected as far as input/output goes. We are expecting the project to be on a relatively large scale feature-wise, and since it is a fictional game, there is always room for more creativity. 

## Phase II

### User Interface Specification
 > Our game consists of a series of simple text dialogue prompts displayed through the console. Specific screens, such as "inventory," must be accessed by inputting specific/corresponding keywords. This will be indicated to the user when the game begins. The general screen format, however, is viewable by default, when navigating through the in-game map, seen below.

### Navigation Diagram
> Expectedly, our screen navigation diagram begins at the title screen, which is visible to the user upon running the executable. After that, all of the screen navigation in our game is directly dependent on how the player traverses through "rooms." Different rooms display different descriptions, but with the same format. The user navigates through rooms by inputting "north," "south," "east," or "west" in the user console, and furthermore, can interact with their belongings directly ("use blowtorch," etc).
> * You can see the in-game map [here](https://media.discordapp.net/attachments/816244007143211048/1206807216745881601/IMG_8986.jpg?ex=65dd59cd&is=65cae4cd&hm=83f6f28548c494030fc3f1690f8aa1ca5aee4b90dd898915514782d6d6f63a85&=&format=webp&width=1266&height=1028), along with the general class definition for "room."
> * You can see the navigation diagram [here](https://media.discordapp.net/attachments/816244007143211048/1210019208025612339/IMG_9166.jpg?ex=65e90934&is=65d69434&hm=191edbfad1dc87de243fd5bab5dacdd0b981289063d75372ad20e8de346516a0&=&format=webp&width=526&height=701). Again, for non-general screens, the title screen is accessed immediately by default, and at any point thereafter, the "inventory" and "help" screens can be accessed using their respective keywords.
> * We've also prepared [sample dialogue](https://docs.google.com/document/d/1negAwdTLN_husnAGGdx1TcFx4Szx91VtEncLmJR0cGs/edit?usp=sharing) for the first couple of rooms. We haven't had the time to sit down and write dialogue for every single room, but each room's initial output will follow the exact same prompt anyway- only the text will differ.

### Screen Layouts
> There are only a few potential dialogue layouts throughout our entire project. All of them are displayed through the user console as simple text outputs- as stated earler, we do not have a GUI. However, these layouts differ slightly in format, as you can see below...
> * The first layout is the [title screen](https://media.discordapp.net/attachments/816244007143211048/1206801982078066768/IMG_8992.jpg?ex=65dd54ed&is=65cadfed&hm=eea047bcbd5a1c62dc0ac3ee5fd0c9dd0d1cc895f5bdb60a046c592de084e929&=&format=webp&width=770&height=1028). This layout is immediately visible to all users upon running the executable. It will be a simple welcome, and will prompt the user to select a difficulty to start the game.
> * The second layout is the [inventory screen](https://media.discordapp.net/attachments/816244007143211048/1206801989783126016/IMG_8991.jpg?ex=65dd54ef&is=65cadfef&hm=5b063c1e25cce77f3bd8a934175481ca61e312d425e1bde201e39d330664d0e5&=&format=webp&width=770&height=1028). This layout is visible to the user when they input the keyword "inventory" after getting past the title screen. It displays the current items in the player's inventory- at the start of the game, it will simply output "you have nothing." In addition, it will likely output the amount of time, steps, and/or HP that the player has remaining (these factors are dependent on the difficulty chosen when presented with the title screen).
> * The third layout is the [help screen](https://media.discordapp.net/attachments/816244007143211048/1206801996829564958/IMG_8990.jpg?ex=65dd54f1&is=65cadff1&hm=a83375e3efe9f5a8b0feba6b0c9b1d1e44feb97d03efecb38108ea9cbbbc15ef&=&format=webp&width=770&height=1028). This layout is visible to the user when they input the word "help" after getting past the title screen. It displays a list of commands that the user can input in order to receive a viable output, in addition to example(s) of how such commands are used. The central commands of our program are "north," "south," "east," and "west," since they allow for the user to develop context, and hence, they will be listed first.
> * The final layout is the [general screen](https://media.discordapp.net/attachments/816244007143211048/1206802004274585661/IMG_8989.jpg?ex=65dd54f3&is=65cadff3&hm=7b031b4eaef25071c4d9e95711d4ed1e1e643215f0a6a0f5a65ef0fdd5348989&=&format=webp&width=770&height=1028). These screens take up a vast majority of the game. Upon navigating from one room to another, the user is prompted with a preset description of the newly-entered room, which will contain information regarding the contents of the room as well as where the player can navigate thereafter (ex: "there is a door in front of you," "there is a can of beans on the floor"). "Spawning" in the first room (immediately after satisfying the title screen) will also greet the user with this same prompt. 
> * You can view all of our currently planned screen layouts simultaneously [here](https://media.discordapp.net/attachments/816244007143211048/1206801974432104448/IMG_8993.jpg?ex=65dd54ec&is=65cadfec&hm=f7f9dd5c5dd9c6b044adfdd13fc713536226624a10555fd7310fe48aeeb83aa7&=&format=webp&width=1370&height=1028).
> We'd like to note that, for the time being, these are just our bare-bones expectations. As we delve into the more technical side of things during our first sprint, we might add an additional screen possibility or two, for the sake of implementing more features (battling, etc). 

### Class Diagram
 > [Here](https://lucid.app/lucidchart/708b8760-c6d6-4327-a22b-1754ad9b0a1a/edit?viewport_loc=-1749%2C-96%2C3642%2C1867%2C0_0&invitationId=inv_72c36e7f-0915-400c-95f5-90b72f1e12d4) is the currently anticipated class diagram for our project. Below, we will include a summary of each currently planned class and what it will do. (LAST UPDATED: 21 February 2023)
> * [CommandParser](https://media.discordapp.net/attachments/816244007143211048/1206827972322000896/IMG_9001.jpg?ex=65dd6d22&is=65caf822&hm=b1428194bf5bafc14f060f9ae0a2cd25973740830f93727f2f5d9d5734d04a15&=&format=webp&width=1370&height=1028): Responsible for interpreting user commands and redirecting said commands to the appropriate class. Also contains the runGame() function, which repeatedly loops and accepts user input until either detecting the word "quit" or expiring.
> * [Map](https://media.discordapp.net/attachments/816244007143211048/1206827971428753448/IMG_9002.jpg?ex=65dd6d22&is=65caf822&hm=b9c0551bcfb39fb64bd4d5a24890bdecdd57416d2719d491eb8f512522f03930&=&format=webp&width=770&height=1028): Responsible for initializing the map, the rooms in the map, and the items in the rooms. It populates the 2D map-pointer array with map objects, constructed with custom item lists and descriptions. Also keeps track of the player's "current location," and can move the location in accordance with user commands (coming from CommandParser).
> * [Room](https://media.discordapp.net/attachments/816244007143211048/1206827970778628156/IMG_9003.jpg?ex=65dd6d22&is=65caf822&hm=77bcc94f561280f1a604cf20746d945a744c6b147fd69e6cb87b16c77f2fdede&=&format=webp&width=1370&height=1028): This can be denoted as a "node." It contains four directional pointers to other rooms, which can be initialized as nullptr. Also contains a vector of items IN the room, and a description of the room that will be displayed upon accessing it.
> * [Item](https://media.discordapp.net/attachments/816244007143211048/1206827970153680896/IMG_9004.jpg?ex=65dd6d21&is=65caf821&hm=45299d5104685ee2525bd9a417ab6a0e02e6b71bda8904b7f2d5b1661aba4807&=&format=webp&width=1370&height=1028): A really simple object with three member variables. As a side note, this one should include getters for name, description, and weight. Populates vectors in both the Room and Player classes. Contains three [derived classes](https://media.discordapp.net/attachments/816244007143211048/1206827969574600704/IMG_9005.jpg?ex=65dd6d21&is=65caf821&hm=62bf1a0e6b938493ee0a64a1354f7f9d80c6c992ab7ae3120ab266a1c0f62b3f&=&format=webp&width=1370&height=1028): consumable, key, and weapon. Key and Weapon are somewhat unlikely to make it into the final cut, but they add the depicted variables/functions to "Item."
> * [Player](https://media.discordapp.net/attachments/816244007143211048/1206827973043425300/IMG_8999.jpg?ex=65dd6d22&is=65caf822&hm=4022978e31c0670ad32ce046ba556dde791f7c195db503ad953cb568343dbfd7&=&format=webp&width=770&height=1028): Represents the values of the player at any given time, such as inventory, health, and steps taken. The status of this class is what determines whether or not the game should keep going (ex: under 0 health means stop). It is possible that we might have to move "position" into this class, but we can't really tell just yet.
> * SIDE NOTES
> ** This was completed on a whiteboard because the factors of each class are really fluid- we don't really know what we'll have to shift around later in the project. We will convert it to a more sustainable file when we have a clearer idea of how it will all come together.
> ** We will most likely prioritize finishing CommandParser and map initialization first. After that, we will begin building the actual puzzles (using items in specific rooms, etc).
 
### Phase III

 **Version 1:** [This](https://media.discordapp.net/attachments/816244007143211048/1206824013544955964/IMG_8995.jpg?ex=65efde72&is=65dd6972&hm=115637ad7ed64f67449a7b43790e16a7f2a6ea224a570fdf7f1db14ae580d48f&=&format=webp&width=935&height=701) is what the class diagram looked like at our first stand-up meeting. This was before we implemented TA feedback or FIRST principles.
 
 **Version 2:** [This](https://media.discordapp.net/attachments/816244007143211048/1213195941729796126/image.png?ex=65f497c4&is=65e222c4&hm=4b43b46f1c25edc57eb15cd2ce7408cbb513699509478b37aaf9e4a740b483e1&=&format=webp&quality=lossless&width=1126&height=701) is what the class diagram looked like after our first TA check-in. We changed the relation between Item and Room, Item and Player, and the relation between Item and it's derived classes. Additionally, we corrected the encapsulation of member variables in the Player and Room classes.

 **Current Version:** [This](https://lucid.app/lucidchart/708b8760-c6d6-4327-a22b-1754ad9b0a1a/edit?invitationId=inv_72c36e7f-0915-400c-95f5-90b72f1e12d4&page=0_0#) is how our current class diagram looks. It is also reflected in the "Phase II" section above.

 We used SOLID design principles in the following specific ways...

 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
