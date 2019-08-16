#!/usr/bin/perl
use strict;
use warnings;
use 5.010;
use FindBin 1.51 qw( $RealBin );
use lib $RealBin;

use Car;
use Engine;
my $car = Car->new( engine => Engine->new(desc=>'this is a engine') );
 
print $car->is_broken ? 'Busted' : 'Still working', "\n";
$car->break;
print $car->is_broken ? 'Busted' : 'Still working', "\n";
 
$car->does('Breakable'); # true
