OUTPUT="pi-openvg-knobs"

run: all
	./$(OUTPUT)

all:
	gcc -I/opt/vc/include \
		-I/opt/vc/include/interface/vmcs_host/linux \
		-I/opt/vc/include/interface/vcos/pthreads \
		$(OUTPUT).c \
		-o $(OUTPUT) \
		-lshapes
