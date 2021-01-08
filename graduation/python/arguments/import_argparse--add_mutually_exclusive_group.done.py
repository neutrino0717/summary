#!/usr/bin/env eepython
import argparse

parser = argparse.ArgumentParser(description='Process some integers.')
parser.add_argument('integers', metavar='N', type=int, nargs='+', help='an integer for the accumulator')
parser.add_argument('--sum', dest='accumulate', action='store_const', const=sum, default=max, help='sum the integers (default: find the max)')
args = parser.parse_args(['1', '2', '3', '4', '--sum'])
print args
print args.accumulate(args.integers)

parser = argparse.ArgumentParser(prog='PROG')
group = parser.add_mutually_exclusive_group()
group.add_argument('--foo', action='store_true')
group.add_argument('--bar', action='store_false')
print parser.parse_args(['--foo'])
print parser.parse_args(['--bar'])
print parser.parse_args(['--foo', '--bar'])
