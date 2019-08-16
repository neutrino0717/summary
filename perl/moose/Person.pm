package Person;
use Moose;

has name => (is => 'rw');
has year => (isa => 'Int', is => 'rw');
has 'birthday' => (isa => 'DateTime', is => 'rw');

1;
