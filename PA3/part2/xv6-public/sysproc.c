#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

/*
The arguments to myV2p()are (1) a
virtual address and (2) the operation (read or write) to the instruction or data in that
address. myV2p() returns the corresponding physical address or the appropriate
error condition*/
int sys_myV2p(){
  int Vp;//Vitural Address
  int operation;
  
  if(argint(0, &Vp) < 0)
    return -1;
  if(argint(1, &operation) < 0)
    return -1;// 0 read, 1 write

  if(operation<0||operation>1)
  {
    cprintf("input invalid in myV2P, 0 for read,1 for write\n");
    return -1;
  }
  struct proc* p=myproc();
  /*
  pde_t* top_level_page_table=p->pgdir;
  int index_into_pgdir=PDX(Vp);//
  pde_t top_level_pte = top_level_page_table[index_into_pgdir];
  cprintf("top level PT for %x in PID %d\n", Vp, p->pid);
  if (top_level_pte & PTE_P) {
      cprintf("is present (valid)\n");
  }
  if (top_level_pte & PTE_W) {
      cprintf("is writable (may be overriden in next level)\n");
  }
  if (top_level_pte & PTE_U) {
      cprintf("is user-accessible (may be overriden in next level)\n");
  }

  cprintf("has base address %x\n", PTE_ADDR(top_level_pte));
  return 1;

*/
    uint physical_address;
    pde_t *pgdir,*pgtab,*pde;
    pgdir=p->pgdir;
    //must initialise pgdir

    pde = &pgdir[PDX(Vp)];
    //*pde points to a physical_location
    if(*pde & PTE_P){
    pgtab = (pte_t*)P2V(PTE_ADDR(*pde));//pgtab virtual 
    }
    else
    {
      cprintf("\n PTE Not Present! - Invalid Virtual address\n");
      return -2;
    }

    
    if(!(*pde & PTE_U)){
      cprintf("\n  This address is Not user-accessible\n");
      return -3;
    }

if(operation==1){// operation is write
   if(!(*pde & PTE_W))
   {
      cprintf("\n  This address is Not Writable\n");
      return -4;
    
   }
}
    
    //cprintf(" Page Directory Entry (PDE): %x\n",*pde);
    //cprintf(" PTE_P : %x\n",PTE_P);
    
    //
    pte_t *pte;
    pte = &pgtab[PTX(Vp)];
    physical_address=(int)(PTE_ADDR(*pte))+(Vp&0x3FF);
    cprintf(" Vitual ADDRESS %x\n",Vp);
    cprintf(" PHYSICAL ADDRESS %x\n\n",physical_address);
    return physical_address;

}


/*
It takes a process id as argument and
will display the different kinds of user pages that have been allocated to the process
or returns an error code
*/
int sys_hasPages(){
  int pid;
  if(argint(0, &pid) < 0){
    return -1;
  }
    if(pid<=0){
    return -1;}


    
return hasPageImp(pid);//in proc.c,we need look up process table

}
