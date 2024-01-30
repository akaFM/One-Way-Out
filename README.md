# One Way Out - A Text-Based RPG

 > Authors: [Avo Karamusyan](https://github.com/akaFM), [Vincent Tang](https://github.com/vtang020), [Andrew Pham](https://github.com/afCS100), [Benjamin Nguyen](https://github.com/Bnguy777)

## Project Description

> ### Why is this project important to us?
> In our coursework up until this point, we've used coding solely for academic purposes. But we've perservered in using it because we are aware that it is an extremely valuable real-world skill and have been anticipating the creation of something more useful. Whether it is for designing webpages or constructing major entertainment titles, coding is used around the world for "real" purposes. "One Way Out" represents the first time that we will use our accumulated skills for something more practical- something that others, especially those who are entirely familiar with computer programming, can enjoy in the real world. This project gives us a chance to present our collective knowledge in the form of something almost everyone can enjoy- a simple computer game.
>
> ### What languages/tools/technologies will we use?
> "One Way Out" will be programmed entirely in C++, using Visual Studio Code for organization and GitHub for collaboration. It won't have a GUI, but will instead rely on user interaction through the console. Since the game is text-based, we have to put in quite a lot of extra effort for immersion purposes, so one of our big objectives is to push the limits of how detailed and interactive a console-based game can get. Since we are exclusively using C++, but still want to show off what we've learned so far, we'll be using a wide variety of techniques for the purpose of creating and maintaining diverse/practical code. Some of these techniques will include inheritance, polymorphism, 2D arrays, and a particular emphasis on object-oriented programming.
>
> ### What will the input/output of our program be?
> As stated earlier, "One Way Out" will be a fully text-based RPG. **Input will be taken in the form of commands and specifications, typed out by the user in the console.** This input will be modified and analyzed with respect to the context of the user's current position in the game, so that we can calculate an adequate **text output through the console**. Text prompts will be detailed and tell the user exactly what to do, but without hindering the extent to which the game is challenging. In our text outputs, we aim to create an appropriate balance between immersion and fun, and in order to accomplish this, our prompts need to be well thought-out and tested (preferrably by people outside of the development team). It is possible that some factors of the game (such as the player's health points, attack power, etc) will be determined by a difficulty chosen by the user, which means that user input has a direct impact on how these factors are computed and displayed.
>
> ### What features will our program provide?
>  * A difficulty setting which allows for user input to directly influence computations made throughout the game (maybe speedrun mode?)
>  * A detailed and thought-out storyline with immersive and informational text outputs
>  * A "stats" system, in which the player can "level up" the character's HP, attack power, and more
>  * A weapons system, in which interacting with different weapons produces different results/outputs (class inheritance)
>  * An array of enemies, which will potentially behave differently altogether, and possibly be in randomized locations
>  * A predetermined map with boundaries, maintained using a 2D array (map can potentially shift like a labyrinth, which would require some sort of algorithm)
>  * A battling system (we don't know much about details, but there needs to be some sort of incentive for the player to stay alert)
>  * An inventory system, entailing objects like keys, which allow for access to certain features/items/locations, and temporarily bar access from others. Also allows for consumables, which will have an effect on the stats system, and so on.
>  * ...and all of the above will likely be very thoroughly bugtested by people outside of the development team, so that we can get a good idea of what is expected as far as input/output goes. We are expecting the project to be on a relatively large scale feature-wise, and since it is a fictional game, there is always room for more creativity. 

 > Your project description should summarize the project you are proposing. Be sure to include:
 > * Why is it important or interesting to you?
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 > * What will be the input/output of your project?
 > * What are the features that the project provides?
 > This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 
 > 
 > You also need to set up an empty project board using GitHub projects (board view with default columns). Make sure you add the board under your project repository. You should also have a Product Backlog and In testing columns added. All columns should be in the right order.
 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column (aka Sprint Backlog).
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. Both time slots should be during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs and expected output, or any graphical user interface components if applicable (e.g. buttons, text boxes, etc). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
 > ## Phase III
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
 
