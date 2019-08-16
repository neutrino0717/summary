#!/usr/bin/perl
use strict;
use warnings;
use 5.010;
use FindBin 1.51 qw( $RealBin );
use lib $RealBin;
use DateTime;

use Person;
my $student = Person->new(name => 'Foo'); say $student->name;
$student->name('Bar');                    say $student->name;
$student->year(1988);                     say $student->year;
$student->birthday( DateTime->new( year => 1988, month => 4, day => 17) ); say $student->birthday
