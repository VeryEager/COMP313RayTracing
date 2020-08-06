COMP313 - Computer Game Development

Asher Stout 300432820

Assignment 1 - Simple Game

"Fox Game: I Couldn't Come Up With A Better Title"

The main action in Fox Game is simple; collect flowers and avoid other foxes. Upon spawning into a level, the user is confronted with a required number of flowers to be collected before they can advance to the next level. Flowers are scattered throughout the level, oftentimes hidden around other environmental objects or in difficult to reach places and are either renewable or non-renewable (ie spawn after a random delay). NPC foxes patrol the level and are neutral unless the player happens to get too close, when they will begin chasing. If caught, the player loses, however NPC foxes are slower, and the Player can use their sprint mechanic & parkour to avoid them. Should the player collect the required number of flowers & return to the delivery point, the level ends with the option to replay.

The most difficult part of the assignment to develop in Unreal was the ending trigger & UI. In my naivety I opted to develop this actor using C++, instead of with blueprints, and very painfully stitched the actor together over several hours and many tutorials. In the future I will be sticking mostly to blueprints when developing UI/HUDs.	Another part of the assignment of difficulty was using the Spawner actor to spawn flower instances after a random delay. I avoided tutorials for this mechanic, using my own knowledge of C++ and the engine to eventually finish the actor, which spawns a Blueprint of CollectibleFlowerItems.

There are several features in this very simple game which I find particularly interesting. The animation state chart for the Fox Character has idle animations that trigger after no inputs from the user, which I particularly enjoy. The Stamina mechanic could easily be extended for mechanics like leveling & powerups, as could the AI for the Fox NPC. Lastly, the spawning of collectibles could be adapted for enemies, powerups, etc, over a dynamic area, opposed to single points. All in all, there is no one aspect of this game I find the most interesting but see the potential of these simple existing mechanics.

Video: https://www.youtube.com/watch?v=Odpl7Qm9ZIY
