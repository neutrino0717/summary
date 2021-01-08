#!/bin/bash
for f in /mnt/lfs/sources/*; do
  if [ -d "$f" ];  then
    sudo rm -rf "$f"
  fi
done

sudo rm -rf /mnt/lfs/tools/*

tree /mnt/lfs/
