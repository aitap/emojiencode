#!/usr/bin/perl
use warnings;
use strict;
use autodie;

die "Usage: $0 <property> < emoji-data.txt > characters.txt\n"
	unless @ARGV == 1;

binmode STDOUT, ":utf8";

while (<STDIN>) {
	chomp;
	s/\s*#.*$//;
	next if /^\s*$/;
	my @fields = split /\s*;\s*/;
	next unless $fields[1] eq $ARGV[0];
	my ($start, $end) = $fields[0] =~ /([0-9A-F]+)(?:\.\.([0-9A-F]+))?/;
	$end //= $start;
	print chr for hex($start)..hex($end);
}
