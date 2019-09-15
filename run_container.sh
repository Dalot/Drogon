#!/bin/bash

docker run --rm --name drogon -p 80:80 -v "$(pwd -W):/home/drogon" drogon:latest