#!/usr/bin/perl
use v5.20;
use warnings;

package Numbase;
use integer;

sub new {
	my ($class, $base, $num) = @_;
	$num //= 0;
	my @digits;
	while ($num) {
		push @digits, $num % $base;
		$num /= $base;
	}
	bless [$base, @digits], $class;
	# $self->[0] is base
	# @{$self}[1 .. $#$self] is digits in $base, little-endian
	# unsigned integers are assumed everywhere
}

use overload '*=' => sub {
	my ($self, $mul) = @_;
	my $ret = ref($self)->new($self->[0]);
	for my $i (1..$#$self) { # for each digit
		# multiply by that digit
		my $add = ref($self)->new($self->[0], $mul * $self->[$i]);
		# shift appropriately
		splice(@$add, 1, 0, (0) x ($i - 1));
		$ret += $add;
	}
	return $ret;
};

use overload '+=' => sub {
	my ($self, $add) = @_;
	# make a long integer out of the summand (required if it's longer than the base)
	$add = ref($self)->new($self->[0], $add) unless ref $add;
	for (my $i = 1; $i <= $#$add; $i++) { # NOTE: $add may be resized by carry
		$self->[$i] += $add->[$i];
		if ($self->[$i] >= $self->[0]) { # carry
			$add->[$i+1] += $self->[$i] / $self->[0];
			$self->[$i] %= $self->[0];
		}
	}
	return $self;
};

use overload '=' => sub { bless [ @{$_[0]} ] };

1;
