_This project has been created as part of the 42 curriculum by lbolea._

# fract-ol
## Description
This project relies on using graphic library [MiniLibX](https://github.com/42paris/minilibx-linux.git) to recreate and display the set of well-know mathematic wonders that are fractals. This project focus on implementing Mandelbrot and Julia sets. Also, I added Multibrot set as bonus.
## Instructions
### Requirements
To compile this project, make sure you got these libraries installed and updated :
``` shell
sudo apt-get update
sudo apt-get install make
sudo apt-get install gcc
sudo apt-get install libXext.so.6
sudo apt-get install libX11.so.6
sudo apt-get install libm.so.6
sudo apt-get install libz.so.1
sudo apt-get install libc.so.6
sudo apt-get install libxcb.so.1
sudo apt-get install libXau.so.6
sudo apt-get install libXdmcp.so.6
sudo apt-get install libbsd.so.0
sudo apt-get install libmd.so.0
```
### Build program
Execute these command inside the directory to :
- Build the program

``` shell
make
```
- Rebuild the program :
``` shell
make re
```
- Clean the objects and dependencies :
``` shell
make clean
```
- Force clean the entire build :
``` shell
make fclean
``` 
- To build the bonus part :
```shell
make bonus
```
### Execute program
To use the program, you can use :
``` shell
./fractol [set options] [animate option]
```
or for the bonus part :
``` shell
./fractol_bonus [set options] [animate option]
```
Here are the available options
``` shell
./fractol mandelbrot animate
./fractol julia [0.00...] [0.00...] animate 
./fractol multibrot animate
```
The option `animate` will active an animated color shift.
Note that Julia set only take positive and negative decimal numbers up to 15 numbers after its integer.
On error, this message will be displayed :
```shell
f6r4s7% ./fractol
 ✘ ERROR  Please enter a correct fractal type : julia, mandelbrol or multibrot.

Choose a type :
➤ mandelbrot animate
➤ julia [(-)0.00...] -[(-)0.00...] animate
➤ multibrot  animate
(add 'animate' option for animated color shifting)
```

### Exemples of interesting Julia sets
```shell
./fractol julia 0 0.8
./fractol julia 0.37 0.1
./fractol julia 0.355 0.355
./fractol julia -0.54 -0.54
./fractol julia -0.4 -0.59
./fractol julia 0.34 -0.05
./fractol julia 0.355534 0.337292
./fractol julia -1.34882125854492 -0.454237874348958
```
Once execute, the program will open a window. To interact with it, you can :
- Use your 🢁, 🢃, 🢀 and 🢂 arrows to move the camera ;
- Use ESC to close the program
- Use your mouse scroll wheel to ⇧ (zoom in) or ⇩ (zoom out) with the camera.
## Resources
[Fractals](https://en.wikibooks.org/wiki/Fractals) - A thorough well documented collaborative open source book on how fractals works, completed along with some helpful speudocode

[MinilibX Prototypes](https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html#mlx_pixel_put) - Some helpful documentation with clear explanations on how the some functions works

[Plotting the Mandelbrot Set by Hand](https://www.wikihow.com/Plot-the-Mandelbrot-Set-By-Hand) - Easy introduction on how the fractal works

[Plotting algorithms for the Mandelbrot set](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set) - A detailled wikipedia article explaining all the main aspects and challenges to implement the Mandenlbrot set

[Fractal animation](https://slicker.me/fractals/animate.htm) - A Javascript tutorial showing how to create a Julia set in few lines of code

[Understanding Julia and Mandelbrot Sets](https://www.karlsims.com/julia.html) - Blog article visually showing how the suite works

[Julia and Mandelbrot Sets](https://lodev.org/cgtutor/juliamandelbrot.html) - An old blog article describing how to create a C++ program for both sets

[HSL and HSV](https://en.wikipedia.org/wiki/HSL_and_HSV#Color_conversion_formulae) - A wikipedia article on how HSV works, a straight forward way to use of the sRGB color space.

[C strod function](https://zetcode.com/clang/strtod/) - A blog tutorial explaining the differents cases of use of strtod function

[Machine Epsilon GNU](https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Machine-Epsilon.html) - A rather important detail to understand when working with floats and doubles

[C Float and Double](https://www.geeksforgeeks.org/c/c-float-and-double/) - A simple introduction to the float and doubles concepts in C

[Cycle detection](https://en.wikipedia.org/wiki/Cycle_detection) - An useful concept that helps to optimize the rendering with periodicity checking, and many others computer science concepts