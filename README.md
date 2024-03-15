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
> * You can see the in-game map [here](https://imgur.com/a/0TYEF2D), along with the general class definition for "room."
> * You can see the navigation diagram [here](https://imgur.com/a/LLcliqE). Again, for non-general screens, the title screen is accessed immediately by default, and at any point thereafter, the "inventory" and "help" screens can be accessed using their respective keywords.
> * We've also prepared [sample dialogue](https://docs.google.com/document/d/1negAwdTLN_husnAGGdx1TcFx4Szx91VtEncLmJR0cGs/edit?usp=sharing) for the first couple of rooms. We haven't had the time to sit down and write dialogue for every single room, but each room's initial output will follow the exact same prompt anyway- only the text will differ.

### Screen Layouts
> There are only a few potential dialogue layouts throughout our entire project. All of them are displayed through the user console as simple text outputs- as stated earler, we do not have a GUI. However, these layouts differ slightly in format, as you can see below...
> * The first layout is the [title screen](https://imgur.com/a/lL1Gd8k). This layout is immediately visible to all users upon running the executable. It will be a simple welcome, and will prompt the user to select a difficulty to start the game.
> * The second layout is the [inventory screen](https://imgur.com/a/gRqMS3o). This layout is visible to the user when they input the keyword "inventory" after getting past the title screen. It displays the current items in the player's inventory- at the start of the game, it will simply output "you have nothing." In addition, it will likely output the amount of time, steps, and/or HP that the player has remaining (these factors are dependent on the difficulty chosen when presented with the title screen).
> * The third layout is the [help screen](https://imgur.com/a/fKvZG2C). This layout is visible to the user when they input the word "help" after getting past the title screen. It displays a list of commands that the user can input in order to receive a viable output, in addition to example(s) of how such commands are used. The central commands of our program are "north," "south," "east," and "west," since they allow for the user to develop context, and hence, they will be listed first.
> * The final layout is the [general screen](https://imgur.com/a/n9jcNEc). These screens take up a vast majority of the game. Upon navigating from one room to another, the user is prompted with a preset description of the newly-entered room, which will contain information regarding the contents of the room as well as where the player can navigate thereafter (ex: "there is a door in front of you," "there is a can of beans on the floor"). "Spawning" in the first room (immediately after satisfying the title screen) will also greet the user with this same prompt. 
> * You can view all of our currently planned screen layouts simultaneously [here](https://imgur.com/a/dZgqjJF).
> We'd like to note that, for the time being, these are just our bare-bones expectations. As we delve into the more technical side of things during our first sprint, we might add an additional screen possibility or two, for the sake of implementing more features (battling, etc). 

### Class Diagram
 > [Here](https://lucid.app/lucidchart/708b8760-c6d6-4327-a22b-1754ad9b0a1a/edit?viewport_loc=-1749%2C-96%2C3642%2C1867%2C0_0&invitationId=inv_72c36e7f-0915-400c-95f5-90b72f1e12d4) is the most up-to-date version of our class diagram.
> * CommandParser: Responsible for interpreting user commands and redirecting said commands to the appropriate class. Also contains the runGame() function, which repeatedly loops and accepts user input until either detecting the word "quit" or expiring.
> * Map: Responsible for initializing the map, the rooms in the map, and the items in the rooms. It populates the 2D map-pointer array with map objects, constructed with custom item lists and descriptions. Also keeps track of the player's "current location," and can move the location in accordance with user commands (coming from CommandParser).
> * Room: This can be denoted as a "node." It contains four directional pointers to other rooms, which can be initialized as nullptr. Also contains a vector of items IN the room, and a description of the room that will be displayed upon accessing it.
> * Item: A really simple object with three member variables. As a side note, this one should include getters for name, description, and weight. Populates vectors in both the Room and Player classes. Contains three derived classes: consumable, key, and weapon. Consumable and Weapon are somewhat unlikely to make it into the final cut, but they add the depicted variables/functions to "Item."
> * Player: Represents the values of the player at any given time, such as inventory, health, and steps taken. The status of this class is what determines whether or not the game should keep going (ex: under 0 health means stop). It is possible that we might have to move "position" into this class, but we can't really tell just yet.
> * SIDE NOTES
> ** We will most likely prioritize finishing CommandParser and map initialization first. After that, we will begin building the actual puzzles (using items in specific rooms, etc).
 
## Phase III

### Class Diagram Updates
>
> Here is the update history for our class diagram...
>
> * **Version 1:** [This](https://imgur.com/a/isY66fK) is what the class diagram looked like at our first stand-up meeting. This was before we implemented TA feedback or FIRST principles.
> * **Version 2:** [This](https://imgur.com/a/tgYywhR) is what the class diagram looked like after our first TA check-in. We changed the relation between Item and Room, Item and Player, and the relation between Item and it's derived classes. Additionally, we corrected the encapsulation of member variables in the Player and Room classes.
> * **Latest Version (15 March 2024):** [This](https://lucid.app/lucidchart/708b8760-c6d6-4327-a22b-1754ad9b0a1a/edit?viewport_loc=-1671%2C-116%2C3699%2C1896%2C0_0&invitationId=inv_72c36e7f-0915-400c-95f5-90b72f1e12d4) **is the latest version of our class diagram**.
>
> When transitioning through the first three versions, we used SOLID design principles in the following specific ways...
>
> * We used the **Single-Responsibility Principle** by encapsulating the member variables of the "Room" class, such as "north," "south," "east," and "west." Via encapsulation, we ensure that the "Room" class is singularly responsible for the control of these variables and not just the storing of them. It can also be argued that this encapsulation exemplifies the **"Open/Closed Principle"**, too, since we are constructing the class such that "getting" one of the directional pointers is open to modification. In another function, we will check if the room actually CAN be entered, but if we implement getters for the directional pointer, we can actually verify that logic IN the getter.
>
> * We used the **Liskov Substitution Principle** and the **Open/Closed Principle** by appropriating the relation between the Item class and it's subclasses such that, first and foremost, any class that utilizes the "Item" class (whether it is as a function parameter, member variable, etc) can reliably use it's subclasses instead without any issue, and second, we will be able to add new "Item" subclasses without having to modify anything else (since the parent class contains all necessary/generic attributes). We made this relationship and it's specifications clear by indicating an "inheritance" relationship AND ensuring that each subclass contains it's own particular function/variable extension(s) in our most updated version of the class diagram.
>
> * We also used the **Liskov Substitution Principle** in our class diagram by clarifying that, in functions which utilize "Item" as a paremeter, subclasses for "Item" can be used in the same way. This is something that is more-so proven in the actual implementation of the code rather than a class-diagram documentation, but we included it in the parameter space for functions like "useItem" or "hasItem" to elaborate on the fact that the "item" parameter in question does not actually have to be of the base class.
>
> * And finally, we used the **Dependency Inversion Principle** in our class diagram by implementing the functions "printRoomName" and "printRoomDescription" as members of the "Map" class. Initially, the "CommandParser" class was expected to call the member functions of the "Room" class (a lower-level module) in order to indicate, in dialogue, the name and description of the user's current position. However, this task was allocated to the Map class such that the CommandParser class no longer has to access anything relating to the Room class at all. This change is a part of the **Dependency Inversion Principle** because it, by nature, relies on the abstraction of the Map class in order to relay appropriate information to the highest-level module. Before, the CommandParser class would have to call the "getName" function of Room and print it, but all of that is automatically completed now by simply calling "printRoomName" in the Map class.

## Final Deliverable
 
### Screenshots
> 
> * [Here](https://cdn.discordapp.com/attachments/894457667878256670/1218257676753043476/image.png?ex=660701e0&is=65f48ce0&hm=1a9691a287dc9768e7c857f2e3922c5b43c1f6988a08c3a762be55f4e0abb06d&) is a picture of the introductory screen, which displays the title and specific difficulties.
> 
> * [Here](https://cdn.discordapp.com/attachments/894457667878256670/1218257773632946206/image.png?ex=660701f7&is=65f48cf7&hm=d0171b0ce7ea8eea71c50089294b492874e313fc49b72a3740cca0cf02894c27&) is a picture of the command menu, which displays the game's available commands.
> 
> * [Here](https://cdn.discordapp.com/attachments/894457667878256670/1218258530927120404/image.png?ex=660702ab&is=65f48dab&hm=8e1a30f5b940c26e13131a3b194334041cd625c2e2be3ac048f9e8cc58f46ee1&) is what it looks like to pick up and examine in item, in addition to the error prompt for misspells.
>
> * [Here](https://cdn.discordapp.com/attachments/894457667878256670/1218272012749766766/image.png?ex=66070f3a&is=65f49a3a&hm=0b05a4764a582da31f1cfb6af7177ccfada553617148e67e1371523a56e72612&) is a screenshot of the "examine" and "use" commands. The "use" command allows the crafting of a paperclip and a bobby pin into a lockpick, which can then be used to unlock a room.
> 
> * [Here](https://cdn.discordapp.com/attachments/894457667878256670/1218261348946022521/image.png?ex=6607054b&is=65f4904b&hm=f224e43c60a7b7c43d4c225e9221520fae70b7fad39f2b43db60ce4b4d23b962&) is what it looks like to lose the game after taking too many steps.
> 
> 
### Installation/Usage
>  * First, make a local clone of the repository using ssh, and make sure you 'git pull' so that all necessary/up-to-date files are included.
>  * Compile the build using the following commands: $ cmake .  $ make
>  * When you compile using CMake and not manually, the test executables will automatically compile alongside the main executable. Because of this, you need to ensure that the gtest submodule is functional. If you receive errors relating to gtest, please run the following command: $ git submodule update --init --recursive. This will ensure that your local copy has successfully cloned the gtest submodule.
>  * Run whichever executable you want to use- "./mainEXE" will start the game.
>  * All instructions on how to play the game will be printed in the console thereafter.
> 
### Testing
> * First and foremost, we tested the program for memory leaks using valgrind. As you can see in [this](https://cdn.discordapp.com/attachments/1208154094460604427/1218169313651986505/image.png?ex=6606af94&is=65f43a94&hm=4c25657fbfc39f22a94be1361e5c08cecea6a4a43e2f1b510b60e429ee3110d6&) attachment, we were able to optimize the program to the extent where it's memory-leak free. An example of a problem that this type of testing solved can be seen in pull request #77. 
> * For unit tests, we used the googletest submodule. [This](https://media.discordapp.net/attachments/1208154094460604427/1218292178464538635/image.png?ex=66072202&is=65f4ad02&hm=35e937de3a7aad756ef8260ec2d0287811454606f09e7afa8b765ef23f7ea370&=&format=webp&quality=lossless&width=761&height=701) and [this](https://media.discordapp.net/attachments/1208154094460604427/1218294581532033114/image.png?ex=6607243f&is=65f4af3f&hm=56bfcae88c311e67ac980a5cee848e1fb138947c2a6f48352c6b2518525e27c4&=&format=webp&quality=lossless&width=414&height=701) are snapshots of some of our unit test outputs. Much of the tests were for somewhat expected inputs, since very little of the functions in our program take direct user input. As we expand in another sprint, one of our objectives is to use the dictation of our unit tests to restructure bulky functions and classes.
>
### Additional Notes
> * The program's class diagram has been fully updated to match code changes. You can see the whole history in the "Phase III" section.
> * Plans for a future sprint, which includes subclasses we didn't get to, are in the "TODO" section of our project board.
