This program is a modified version of Junlee Kim's
macro. 

##################################################
HOW TO COMPILE:

The project is provided with "Makefile" and the 
compilation is done with make -command. The 
compilation requires Fastjet and Pythia 8 to be 
installed. Paths to these installations are 
expected to be exported as follows.

"export FASTJET=/path/to/your/fastjet-install"
"export PYTHIA8=/path/to/your/pythia8306"

##################################################
HOW TO RUN:

NOTE: To run this program one needs to have
Fastjet and Pythia 8 libraries exported to 
LD_LIBRARY_PATH. i.e. need to type this command: 

"export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/
your/fastjet-install/lib:/path/to/your/pythia8306/
lib"

The input file folder is counter-intuitively the
outputs/ folder which contains outputs of the 
previous step in this whole analysis. 
An input file is passed to the program as a text
file as a command line argument. 

E.g. the input file is called "input.root" and 
is located in the outputs folder. Then one 
creates a text file with text "outputs/input.root"
(w/o quotation marks). This text file is then
passed as a command line argument to the program.

In addition to the input file one has to define 
an output file too as a command line argument.
The output filename is passed as the first 
argument whereas the input file is passed as the 
second argument. Note that the output filename is
passed just as it is and not via text file.

An example run would be:

./CMS-analysis analysis/output.root inputfilename.txt
