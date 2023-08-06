{ pkgs ? import <nixpkgs> {} }:

with pkgs;

gcc13Stdenv.mkDerivation rec {
    pname = "openfhe";
    version = "1.0.4";
    src = fetchgit {
        url = "https://github.com/openfheorg/openfhe-development.git";
        rev = "v1.0.4";
        sha256 = "d24bbe1149b580ea749b5c6c85b87d6ce4bdd05e8d62644952d95e8173374787";
    };

    buildInputs = [
        cmake
    ];

    cmakeFlags = [
        "-DBUILD_UNITTESTS=OFF"
        "-DBUILD_EXAMPLES=OFF"
        "-DBUILD_BENCHMARKS=OFF"
        "-DBUILD_EXTRAS=OFF"
    ];
}
