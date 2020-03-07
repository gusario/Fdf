FdF
=====


<img width="1278" alt="Screenshot 2020-03-07 at 15 48 10" src="https://user-images.githubusercontent.com/44320468/76143737-ff1c0080-608a-11ea-9952-fd2de0d9d5d9.png">

This project is about creating a simplified graphic “wireframe” (“**fils de fer**” in french,
hence the name of the project) representation of a relief landscape linking various points
(x, y, z) via segments using [Bresenham's line algorithm](https://uk.wikipedia.org/wiki/Алгоритм_Брезенхейма).
The coordinates of this landscape are stored in a file passed as
a parameter to your program. Examples you can find in the folder ```maps```.
Use my maps or create your own.
Each number corresponds to a point in space:
* The horizontal position corresponds to its axis
* The vertical position corresponds to its ordinate
* The value corresponds to its altitude

Interesting features:
-----
* [Rotating](http://grafika.me/node/82)
* Moving
* Zooming
* Relief changing
* Gradient lines

Run the project:
-----
```
git clone https://github.com/gusario/Fdf.git
cd Fdf
make
./fdf maps/example.fdf
```
:green_apple: Works only on **Mac OS**

<img width="1278" alt="Screenshot 2020-03-07 at 15 52 32" src="https://user-images.githubusercontent.com/44320468/76143813-9b460780-608b-11ea-9848-610aa2047743.png">
