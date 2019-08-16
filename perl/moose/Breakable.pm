package Breakable;  #Creating a role looks a lot like creating a Moose class:
 
use Moose::Role;   #so 'Breakable' is a Role (similar to Java Interface)
 
has 'is_broken' => (             #is_broken attribute
    is  => 'rw',
    isa => 'Bool',
);
 
sub break {                      #break method
    my $self = shift;
 
    print "I broke\n";
 
    $self->is_broken(1);
};

1;
