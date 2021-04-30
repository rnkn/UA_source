#include "includes.h"
#include "nucleas.h"
#include "sample.h"
#include "utils.h"


const Nucleus::ClassDescr NC_STACK_sample::description("sample.class", &newinstance);


size_t NC_STACK_sample::Init(IDVList &stak)
{
    if ( !NC_STACK_rsrc::Init(stak) )
        return 0;

    stack__sample.p_sampl = (TSampleData *)getRsrc_pData();

    return 1;
}

rsrc * NC_STACK_sample::rsrc_func64(IDVList &stak)
{
    rsrc *res = NC_STACK_rsrc::rsrc_func64(stak);

    if ( !res )
        return NULL;

    int bufsz = stak.Get<int32_t>(SMPL_ATT_LEN, 0);
    int type = stak.Get<int32_t>(SMPL_ATT_TYPE, 0xFFFF);

    if ( bufsz == 0 || type == 0xFFFF )
        return res;

    TSampleData *smpl = (TSampleData *)AllocVec(sizeof(TSampleData), 65537);

    if ( !smpl )
        return res;

    smpl->bufsz = bufsz;
    smpl->field_8 = type;

    void *buf = stak.Get<void *>(SMPL_ATT_BUFFER, NULL);

    if ( !buf )
    {
        buf = AllocVec(bufsz, 65537);
        smpl->Data = buf;

        if ( !buf )
        {
            nc_FreeMem(smpl);
            return res;
        }
    }
    else
    {
        smpl->Data = buf;
        smpl->field_10 |= 1;
    }

    res->data = smpl;

    return res;
}

size_t NC_STACK_sample::rsrc_func65(rsrc *res)
{
    TSampleData *smpl = (TSampleData *)res->data;

    if ( smpl )
    {
        if ( !(smpl->field_10 & 1) )
        {
            if ( smpl->Data )
                nc_FreeMem(smpl->Data);
        }
        nc_FreeMem(smpl);
        res->data = NULL;
    }

    return NC_STACK_rsrc::rsrc_func65(res);
}

void * NC_STACK_sample::sample_func128(void **arg)
{
    printf("%s - NOT RECOGINZED ARGUMENT\n","sample_func128");
    TSampleData *smpl = stack__sample.p_sampl;
    arg[2] = smpl;
    return smpl;
}



TSampleData *NC_STACK_sample::GetSampleData()
{
    return stack__sample.p_sampl;
}

int NC_STACK_sample::getSMPL_type()
{
    if (stack__sample.p_sampl)
        return stack__sample.p_sampl->field_8;
    return 0;
}

int NC_STACK_sample::getSMPL_len()
{
    if (stack__sample.p_sampl)
        return stack__sample.p_sampl->bufsz;
    return 0;
}

void *NC_STACK_sample::getSMPL_buffer()
{
    if (stack__sample.p_sampl)
        return stack__sample.p_sampl->Data;
    return 0;
}



