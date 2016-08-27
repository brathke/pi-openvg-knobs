OUTPUT="pi-openvg-knobs"

all:
	gcc -I/opt/vc/include -I/opt/vc/include/interface/vmcs_host/linux -I/opt/vc/include/interface/vcos/pthreads test.c -o $(OUTPUT) -lshapes
