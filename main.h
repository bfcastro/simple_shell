#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* _Points to an ar_ray of point__ers to stri_ngs call__ed the "env__ironment" */
extern char **environ;


/**
 * st__ruct data - st_ruct with all re_levant data on r_untime
 * @av: _argument _array
 * @input: _user i_nput _at _-cmd
 * @args: __tokens of t__he cmd_ l__ine
 * @status: l_ast sta_tus of t_he she_ll
 * @counter: _li_nes co_unter
 * @_environ: en_vironment _var
 * @pid: _process I_D of t__he s__hell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - __single l__inked list
 * @separator: ; | &
 * @next: __next node
 * Description: single l__inked list to s__tore separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct __line_list_s - s__ingle linked list
 * @line: com_mand line
 * @next: n__ext node
 * Description: __single linked __list to _-store __com_mand lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - s_ingle _linked list
 * @len_var: le_ngth of t_he __var
 * @val: __value o_-f the v_-ar
 * @len_val: leng_th of the value
 * @next: __next __node
 * Description: __single lin_ked l_ist to sto_re vars
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Bu_ilt_in struct for _comma_nd _-args.
 * @name: T__he name of the __command built_in i.e cd, __exit, env
 * @f: data __type poi_-nter f__unction.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* handle_linked_list.c */
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);

/* display_help.c */
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

/* str_manipulation.c */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* handle_memory.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* str_manipulation1.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* str_manipulation2.c */
void rev_string(char *s);

/* check_str_syntax_error.c */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(data_shell *datash, char *input, int i, int bool);
int check_syntax_error(data_shell *datash, char *input);

/* shell_loop.c */
char *without_comment(char *in);
void shell_loop(data_shell *datash);

/* read_line.c */
char *read_line(int *i_eof);

/* parse_tokenize.c */
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);

/* handle_environment_vars.c */
void check_env(r_var **h, char *in, data_shell *data);
int check_vars(r_var **h, char *in, char *st, data_shell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, data_shell *datash);

/* get_line_str.c */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* check_builtin.c */
int exec_line(data_shell *datash);

/* execute_command.c */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);

/* environment_vars.c */
char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);

/* environment_vars1.c */
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

/* change_dir.c */
void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);

/* change_dir_shell.c */
int cd_shell(data_shell *datash);

/* get_builtin */
int (*get_builtin(char *cmd))(data_shell *datash);

/* exit_shell.c */
int exit_shell(data_shell *datash);

/* int_str_conversion.c */
int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

/* error_msg.c */
char *strcat_cd(data_shell *, char *, char *, char *);
char *error_get_cd(data_shell *datash);
char *error_not_found(data_shell *datash);
char *error_exit_shell(data_shell *datash);

/* error_msg1.c */
char *error_get_alias(char **args);
char *error_env(data_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(data_shell *datash);


/* get_error_msg.c */
int get_error(data_shell *datash, int eval);

/* signal_handler.c */
void get_sigint(int sig);

/* help_info.c */
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);

/* help_info1.c */
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

/* get_help_info.c */
int get_help(data_shell *datash);

#endif
