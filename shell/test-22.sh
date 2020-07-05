#!/bin/bash

# redirecting file input

exec 3>testfile

echo “This should display on the monitor ”
