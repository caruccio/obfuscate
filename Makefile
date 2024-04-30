.ONESHELL:
.EXPORT_ALL_VARIABLES:

all build:
	@if [ -z $$PASSWORD ]; then
		read -s -t 30 -p "Password: " PASSWORD
	fi
	g++ main.cpp -D PASSWORD=\"$$PASSWORD\" -o obfuscate

encrypt:
	@echo "$$TOKEN" | openssl enc -e -aes-256-cbc -base64 -k $(shell ./obfuscate) -iter 1000

decrypt:
	@echo "$$TOKEN" | openssl enc -d -aes-256-cbc -base64 -k $(shell ./obfuscate) -iter 1000

clean-decrypt:
	@echo "$$TOKEN" | openssl enc -d -aes-256-cbc -base64 -k $(shell ./obfuscate --delete) -iter 1000
