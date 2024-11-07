{
	description = "Flake for the jura terminal text editor";

	inputs = {
		nixpkgs.url = "github:Nixos/nixpkgs/nixos-unstable";
		utils.url = "github:numtide/flake-utils";
	};

	outputs = { self, nixpkgs, utils }:
		utils.lib.eachDefaultSystem (system:
			let
				pkgs = import nixpkgs { inherit system; };
			in
			{
				packages.default = pkgs.callPackage ./default.nix { };
			});
}