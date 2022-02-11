# Snow Toss
Snow Toss! Our Winter themed game. Using the provided scene, you will be creating a projectile/shooter based game. Toys should pop up out of the present boxes, and our Hero needs to hit them with a snowball!

**DISCLAIMER**: The assets provided in this project are for personal use only. **DO NOT** use them in your commercial projects unless you have purchased them yourself from the Unreal Marketplace.
## Required Mechanics:
* Countdown timer that indicates when the game begins
* A random one of the 3 presents fire out toys that can be hit
* Toys that appear are randomized
* Indicate when toys have been hit through visual queues on HUD and sounds
* Each Toy has a different point value
* End of match screen that shows the results(Total points earned from hitting toys)

## Bonus Examples:
Be creative! As long as the above Required Mechanics are met, we encourage you to add to them/adapt them in any way you like! Here are some examples of things that can be done:
* Visual effect when Snowball makes contact with environment/toys
* Visual effect when Toys are successfully hit
* Show the images of each toy successfully hit
* If duplicate toys are hit, stack them in the results screen and show their total points earned
* Higher score for faster hit( time on screen for targets effects score)

## Due Date:
You will have just over two weeks to complete this challenge. All challenges must be submitted by **Monday, December 20th**.

## How to Submit:
Record a video playthrough of your challenge, name it **Challenge002_YourName**, and post it on the #open_session-programming channel by the due date.

## Project Organization:
The Project is organized by Challenge Assets and Global Assets. Challenge Assets are anything related to that specific challenge (Meshes, Blueprints, Audio, Materials, etc). Global Assets are anything that will be used in multiple challenges, most notably the character and their animations, blueprints, materials, etc.

### Important Challenge Assets:
Primarily for this challenge you will be focusing on the following assets:

#### Blueprints:

**File Path: GMC/Challenges/Challenge_002_SnowToss/Blueprints**
* BP_GMCHero_002
* BP_Snowball
* BP_PresentLauncher
* BP_GMCPlayerController_002
* BP_GMCGameMode_002

**File Path: GMC/Challenges/Challenge_002_SnowToss/UI**
* WBP_002_HUD
* WBP_002_HitPoints
* WBP_002_ToyStat

#### Animations:
**File Path: GMC/Challenges/Challenge_002/Animation**
* AnimBP_CGS_Hero_002
* BS_IdleWalkRun_Snowball
* ThrowMontage

#### Data:
**File Path: GMC/Challenges/Challenge_002/Data**
* DT_ToyList
* FToyData

#### Maps
**File Path: GMC/Challenges/Challenge_002_SnowToss/Maps**
* Challenge_002
