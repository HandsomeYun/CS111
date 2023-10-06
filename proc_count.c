#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

static struct proc_dir_entry *entry;

static int proc_count(struct seq_file *m, void *v)
{							  // m is a pointer to a file that will formate the output, and v is a pointer that can pass additional data to operation
	struct task_struct *task; // pointerto task structure that represents a process
	int count = 0;			  // count the number of process
	for_each_process(task)
	{
		count++;
	}
	seq_printf(m, "%d\n", count);
	return 0;
}

static int __init proc_count_init(void)
{
	entry = proc_create_single("count", 0, NULL, proc_count); // creare a file named "count" with file mode 0, parent directory = null. and file operations = proc_count
	if (!entry)
	{
		pr_err("proc_count: failed to create /proc/count entry \n");
		return -ENOMEM; // Error code for out-of-memory
	}
	pr_info("proc_count: init\n");
	return 0;
}

static void __exit proc_count_exit(void)
{
	proc_remove(entry);
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("CS111 lab0 count proc number");
MODULE_LICENSE("GPL");