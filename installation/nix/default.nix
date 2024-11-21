{ pkgs ? import <nixpkgs> {} }:

pkgs.clangStdenv.mkDerivation rec{
	pname = "jura";
	version = "5.0";

	src = pkgs.fetchFromGithub {
		owner = "Nooberieno";
		repo = "jura";
		rev = ${version};
		sha256 = "";
	};

	buildInputs = [ ];

	makeflags = [ "INSTALL_DIR=$(out)/bin" ];

	installPhase = ''
		mkdir -p $out/bin
		cp jura $out/bin
	'';

	meta = with pkgs.lib; {
		description = "A small, lightweight terminal text editor";
		homepage = "https://github.com/Nooberieno/jura";
		maintainers = with maintainers; [ Nooberieno ];
		platforms = platforms.unix
	}
}