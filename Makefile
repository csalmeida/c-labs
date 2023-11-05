all: docker
	docker compose up --detach
	docker exec -it clang /bin/bash 