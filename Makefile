all: docker
	docker compose up -d
	docker exec -it clang /bin/bash 