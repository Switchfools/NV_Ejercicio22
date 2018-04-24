escalon.png : Grafica.py diffusion.txt
	python3 Grafica.py
diffusion.txt : diffusion
	./diffusion>diffusion.txt
diffusion :Second.cpp
	c++ Second.cpp -o diffusion