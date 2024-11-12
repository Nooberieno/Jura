class Jura < Formula
	desc "A small, lightweight terminal text editor"
	homepage "https://github.com/Nooberieno/jura"
	url "https://github.com/Nooberieno/jura/.git", branch: "jura-rewrite"
	version "5.0"
	license "MIT"

	depends_on "make" => :build

	def install
		system "make", "jura"
		bin.install "jura"
	end
end