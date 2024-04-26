{
  description = "Development env with gcc";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: 
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
    in {
      devShells.${system}.default = pkgs.mkShell {
        packages = with pkgs; [
          libgcc 
          man-pages
          man-pages-posix
        ];

        shellHook = ''
          exec zsh
        '';
      };
    };
}
