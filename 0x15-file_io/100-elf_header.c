#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_elf_header_info(Elf64_Ehdr *header)
{
	printf("  Magic:   ");
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
	printf("  Class: %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:  %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's, little-endian" : "2's, big-endian");
	printf("  Version: %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI: %d\n", header->e_ident[EI_OSABI]);
	printf("  ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type: %d (EXEC)\n", header->e_type);
	printf("  Entry point address:               %#lx\n", header->e_entry);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
		exit(98);
	}

	Elf64_Ehdr elf_header;

	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
	fprintf(stderr, "Error: Cannot read ELF header from file %s\n", argv[1]);
	close(fd);
	exit(98);
	}

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 || elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
	elf_header.e_ident[EI_MAG2] != ELFMAG2 || elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: %s is not an ELF file\n", argv[1]);
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");
	print_elf_header_info(&elf_header);

	close(fd);
	return (0);
}

