#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_elf_header - prints the ELF header information
 *
 * @header: pointer to the ELF header structure
 */
void print_elf_header(Elf64_Ehdr *header)
{
  int i;

  printf("Magic:   ");
  for (i = 0; i < EI_NIDENT; i++)
    printf("%02x ", header->e_ident[i]);
  printf("\nClass:                             %s\n",
         header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
  printf("Data:                              %s\n",
         header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
  printf("Version:                           %d\n", header->e_ident[EI_VERSION]);
  printf("OS/ABI:                            ");
  switch (header->e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
      printf("UNIX - System V\n");
      break;
    case ELFOSABI_HPUX:
      printf("UNIX - HP-UX\n");
      break;
    case ELFOSABI_NETBSD:
      printf("UNIX - NetBSD\n");
      break;
    case ELFOSABI_LINUX:
      printf("UNIX - Linux\n");
      break;
    case ELFOSABI_SOLARIS:
      printf("UNIX - Solaris\n");
      break;
    case ELFOSABI_IRIX:
      printf("UNIX - IRIX\n");
      break;
    case ELFOSABI_FREEBSD:
      printf("UNIX - FreeBSD\n");
      break;
    case ELFOSABI_TRU64:
      printf("UNIX - TRU64\n");
      break;
    case ELFOSABI_ARM_AEABI:
      printf("ARM EABI\n");
      break;
    default:
      printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
    }
  printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
  printf("Type:                              ");
  switch (header->e_type)
    {
    case ET_NONE:
      printf("NONE (No file type)\n");
      break;
    case ET_REL:
      printf("REL (Relocatable file)\n");
      break;
    case ET_EXEC:
      printf("EXEC (Executable file)\n");
      break;
    case ET_DYN:
      printf("DYN (Shared object file)\n");
      break;
    case ET_CORE:
      printf("CORE (Core file)\n");
      break;
    default:
      printf("<unknown: %x>\n", header->e_type);
    }
  printf("Entry point address:               %#lx\n", header->e_entry);
}

/**
 * main - entry point for the program
 *
 * @argc: number of command-line arguments passed to the program
 * @argv: array of command-line arguments passed to the program
 *
 * Return: On success, returns zero. On failure, returns non-zero.
 */
int main(int argc, char **argv)
{
  int fd;
  Elf64_Ehdr header;

  if (argc != 2)
    {
      fprintf(stderr, "Usage: elf_header elf_filename\n");
      return (98);
    }

  fd = open(argv[1], O_RDONLY);
  if (fd == -1)
    {
      fprintf(stderr, "Error: cannot open file '%s'\n", argv[1]);
      return (98);
    }

  if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
      fprintf(stderr, "Error: cannot read ELF header from file '%s'\n", argv[1]);
      close(fd);
      return (98);
    }

  if (lseek(fd, header.e_shoff, SEEK_SET) == -1)
    {
      fprintf(stderr, "Error: cannot seek to section headers in file '%s'\n

