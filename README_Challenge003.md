# Musical Throne
Win the throne in a game of Musical Chairs! Using the provided scene, you will be creating a interactive musical game against AI players. When the music begins, players will run around in a circle and when it stops, they must quickly get to a chair or be eliminated! After three rounds, a winner will be decided and be crowned as the new King!

**DISCLAIMER**: The assets provided in this project are for personal use only. **DO NOT** use them in your commercial projects unless you have purchased them yourself from the Unreal Marketplace.
## Required Mechanics:
* Progress through 3 rounds, spawning the appropriate amount of chairs each time.
* After each round, reset the player to the starting point.
* The final round spawns a single throne.
* After the final round, a winner is chosen and is represented on the throne next to the queen.

## Bonus Examples:
Be creative! As long as the above Required Mechanics are met, we encourage you to add to them/adapt them in any way you like! Here are some examples of things that can be done:
* Push you skills and develop the provided AI to participate in the game
* AI's should wait for music to start, run around in circles, and attempt to reach a chair when the music stops.
* If an AI wins, they should be the one represented on the chair at the end.
* Super Bonus: Players and AI have a way to impede each other's progress.
* Super Bonus: This game can be played multiplayer over network or locally with friends.

## Due Date:
You will have just over two weeks to complete this challenge. All challenges must be submitted by **Monday, February 28th**.

## How to Submit:
Record a video playthrough of your challenge, name it **Challenge003_YourName**, and post it on the #open_session-programming channel by the due date.

## Project Organization:
The Project is organized by Challenge Assets and Global Assets. Challenge Assets are anything related to that specific challenge (Meshes, Blueprints, Audio, Materials, etc). Global Assets are anything that will be used in multiple challenges, most notably the character and their animations, blueprints, materials, etc.

### Important Challenge Assets:
Primarily for this challenge you will be focusing on the following assets:

#### Blueprints:

**File Path: GMC/Challenges/Challenge_003_MusicalThrone/Blueprints**
* Characters/BP_GMCHero_003
* Characters/BP_AI_003
* BP_Chair
* BP_Throne
* BP_Wall
* Controllers/BP_GMCPlayerController_003
* Controllers/BP_GMC_AIController_003
* BP_GMCGameMode_003
* BP_StartingPlatform

**File Path: GMC/Challenges/Challenge_003_MusicalThrone/AI**
* BB_Default
* BT_Default
* EQS/EQS_Wander

**File Path: GMC/Challenges/Challenge_003_MusicalThrone/UI**
* WBP_003_HUD

#### Animations:
**File Path: GMC/Challenges/Challenge_003_MusicalThrone/Animations**
* AnimBP_CGS_Hero_003
* AnimBP_AICGSHero_003

#### Maps
**File Path: GMC/Challenges/Challenge_003_MusicalThrone/Maps**
* Challenge_003
