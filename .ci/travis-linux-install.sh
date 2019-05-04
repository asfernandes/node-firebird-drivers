#!/bin/sh

wget -O Firebird-3.0.3.32900-0.amd64.tar.gz "https://github.com/FirebirdSQL/firebird/releases/download/R3_0_3/Firebird-3.0.3.32900-0.amd64.tar.gz"
tar xzvf Firebird-3.0.3.32900-0.amd64.tar.gz
(cd Firebird-3.0.3.32900-0.amd64; sudo ./install.sh -silent)
sudo usermod -a -G firebird travis
