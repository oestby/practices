FROM ubuntu:16.04
MAINTAINER Oskar Østby

RUN apt-get update -qq && apt-get install -qqy \
    build-essential \
    cmake \
    make \
    git

COPY ./build_dependencies.sh /
RUN /bin/bash ./build_dependencies.sh
RUN rm build_dependencies.sh


COPY ./ /workspace
WORKDIR /workspace
RUN /bin/bash ./build.sh
