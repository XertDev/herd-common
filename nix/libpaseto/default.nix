{ pkgs ? import <nixpkgs> {} }:

with pkgs;

gcc13Stdenv.mkDerivation rec {
    pname = "libpaseto";
    version = "1.0";
    src = fetchgit {
        url = "https://github.com/authenticvision/libpaseto.git";
        rev = "c447292";
        sha256 = "dcd42416273c99e8ed442abcfd24a49777e30d588a7c9fe785c08d3b6ae5bdb5";
    };

    nativeBuildInputs = [
        pkgconfig
        cmake
        libsodium
    ];

    buildPhase = ''
        cmake --build . --target paseto -j$NIX_BUILD_CORES
    '';

    installPhase = ''cmake --install .'';
}
