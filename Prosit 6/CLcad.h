#pragma once

// Ajoutez cette ligne pour résoudre les erreurs
using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

namespace NS_Comp_Data
{
    ref class CLcad
    {
    private:
        SqlConnection^ oCnx;
        SqlCommand^ oCmd;
        SqlDataAdapter^ oDA;
        DataSet^ oDs;
        String^ sCnx;
        String^ sSql;

    public:
        CLcad(void);
        ~CLcad(void);

        void beginTransaction();
        void commitTransaction();
        void rollbackTransaction();

        DataSet^ getRows(System::String^ sSql, System::String^ sDataTableName);
        void actionRows(System::String^ sSql);
    };
}
