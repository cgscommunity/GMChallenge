# Whack-A-Zombie
Whack-A-Zombie! Our Halloween themed Whack-A-Mole game. Using the provided scene, you will be creating a Whack-A-Mole style game. Zombie hands should rise from randomized dirt patches in the ground, and players should be able to hit them and earn points for each zombie hand they hit. See the attached video for an example of the final results.

**DISCLAIMER**: The assets provided in this project are for personal use only. **DO NOT** use them in your commercial projects unless you have purchased them yourself from the Unreal Marketplace.
## Required Mechanics:
* Countdown to start the game
* Zombie hands randomly raise from dirt patches in the ground (how many is up to you!)
* Players can hit the Zombie hands when they are raised and it will update the HUD to show their score.
* Players have a limited time to hit as many hands as they can which is displayed as a timer in the HUD.
* End of match screen that shows the total hands hit and the total zombie hands spawned.

## Bonus Examples:
Be creative! As long as the above Required Mechanics are met, we encourage you to add to them/adapt them in any way you like! Here are some examples of things that can be done:
* An effect triggers when hands are hit
* Random exposed hand duration
* Hands have health
* Player has health and can be damaged if walking into a hand
* An extra spin attack that hits multiple hands in the area (there is a provided second attack animation for this)

## Due Date:
You will have two weeks to complete this challenge. All challenges must be submitted by **Sunday, November 7th**.

## How to Submit:
Record a video playthrough of your challenge, name it **Challenge001_YourName**, and post it on the #open_session-programming channel by the due date.

## Project Organization:
The Project is organized by Challenge Assets and Global Assets. Challenge Assets are anything related to that specific challenge (Meshes, Blueprints, Audio, Materials, etc). Global Assets are anything that will be used in multiple challenges, most notably the character and their animations, blueprints, materials, etc.

### Important Challenge Assets:
Primarily for this challenge you will be focusing on the following assets:

#### Blueprints:

**File Path: GMC/Challenges/Challenge_001/Blueprints**
* BP_GMCGameMode_001
* BP_ZombieGrid
* BP_ZombieHand

**File Path: GMC/Challenges/Challenge_001/UI**
* WBP_HUD

**File Path: GMC/GlobalAssets/Characters/Blueprints**
* BP_GMCHero

### Animations:
**File Path: GMC/GlobalAssets/Characters/Animations**
* Character Animations

**File Path: GMC/Challenges/Challenge_001/Meshes/Props/ZombieHand/Animations**
* Zombie Hand Animations
* ZombieHandMontage
