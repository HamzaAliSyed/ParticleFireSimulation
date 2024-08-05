all:
	g++ -I src/include -L src/lib -o ParticleExplosion main.cpp screen.cpp particle.cpp swarm.cpp -lmingw32 -lSDL2main -lSDL2