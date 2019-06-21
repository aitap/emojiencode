#!/usr/bin/perl
use warnings;
use strict;
use autodie;
use FindBin;
use lib "$FindBin::Bin";
use Numbase;

die "Usage: $0 <table.utf8> <encode?>\n"
	unless @ARGV == 2;

# set up transformation tables

my @emoji = split //, do { open my $fh, "<:encoding(UTF-8)", $ARGV[0]; local $/; <$fh>; };
my %src; my @dest;

if ($ARGV[1]) {
	binmode STDOUT, ":utf8";
	$src{chr $_} = $_ for 0..255;
	@dest = @emoji;
} else {
	binmode STDIN, ":encoding(UTF-8)";
	%src = map { $emoji[$_], $_ } 0..$#emoji;
	$dest[$_] = chr $_ for 0..255;
}

local $/ = \1;

my $sbase = scalar keys %src;
my $state = Numbase::->new(scalar @dest);
while (<STDIN>) {
	my $add = $src{$_} // next;
	$state *= $sbase;
	$state += $add;
}
print join '', map { $dest[$_] } reverse @{$state}[1..$#$state];
print "\n" if $ARGV[1];
