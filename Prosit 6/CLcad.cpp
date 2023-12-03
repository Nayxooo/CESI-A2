#include "pch.h"
#include "CLcad.h"

using namespace System::Data::SqlClient;

NS_Comp_Data::CLcad::CLcad(void)
{
    sCnx = "Data Source=laptop-mg4fahso\\dbcesi;Initial Catalog=Students_POO;Integrated Security=True";
}

NS_Comp_Data::CLcad::~CLcad(void)
{
    // Ajoutez ici la logique de nettoyage si nécessaire
}

void NS_Comp_Data::CLcad::beginTransaction()
{
    SqlConnection^ oCnx = gcnew SqlConnection(this->sCnx);
    SqlCommand^ oCmd = gcnew SqlCommand("", oCnx);
    oDA = gcnew SqlDataAdapter();
    oDs = gcnew DataSet();

    oCmd->CommandType = CommandType::Text;

    oCnx->Open();
    oCmd->Transaction = oCnx->BeginTransaction();
}

void NS_Comp_Data::CLcad::commitTransaction()
{
    oCmd->Transaction->Commit();
    oCnx->Close();
}

void NS_Comp_Data::CLcad::rollbackTransaction()
{
    oCmd->Transaction->Rollback();
    oCnx->Close();
}

System::Data::DataSet^ NS_Comp_Data::CLcad::getRows(System::String^ sSql, System::String^ sDataTableName)
{
    SqlConnection^ oCnx = gcnew SqlConnection(sCnx);
    SqlCommand^ oCmd = gcnew SqlCommand(sSql, oCnx);
    SqlDataAdapter^ oDA = gcnew SqlDataAdapter();
    DataSet^ oDs = gcnew DataSet();

    oCmd->CommandType = CommandType::Text;

    oCnx->Open();
    oCmd->CommandText = sSql;
    oDA->SelectCommand = oCmd;

    try
    {
        oDA->Fill(oDs, sDataTableName);
    }
    finally
    {
        oCnx->Close();
    }

    return oDs;
}

void NS_Comp_Data::CLcad::actionRows(System::String^ sSql)
{
    SqlConnection^ oCnx = gcnew SqlConnection(sCnx);
    SqlCommand^ oCmd = gcnew SqlCommand(sSql, oCnx);
    SqlDataAdapter^ oDA = gcnew SqlDataAdapter();

    oCmd->CommandType = CommandType::Text;

    oCnx->Open();
    oCmd->Transaction = oCnx->BeginTransaction();

    try
    {
        oCmd->ExecuteNonQuery();
        oCmd->Transaction->Commit();
    }
    catch (...)
    {
        oCmd->Transaction->Rollback();
        throw;
    }
    finally
    {
        oCnx->Close();
    }
}
