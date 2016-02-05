# https://wiki.archlinux.org/index.php/GPGPU
# sudo pacman -S nvidia cuda

INCLUDES=

helloworld: hello-world.cu 
		nvcc hello-world.cu -L /usr/local/cuda/lib -lcudart -o hello-world
