package Car;
 
use Moose;           #so Car is a class
 
with 'Breakable';    #The 'with' function composes 'Breakable' role into class 'Car'
 
has 'engine' => (
    is  => 'ro',
    isa => 'Engine',
);

1;
