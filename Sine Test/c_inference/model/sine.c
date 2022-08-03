// This file is computer-generated by onnx2c 
// (TODO: add creating command line here)
// (TODO: print creation date here )

// ONNX model:
// produced by tf2onnx, version 1.12.0 a58786
// ONNX IR version: 13
// Model documentation: 
/*

*/

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define MAX(X,Y) ( X > Y ? X : Y)
#define MIN(X,Y) ( X < Y ? X : Y)
#define CLIP(X,L) ( MAX(MIN(X,L), -L) )

static const float tensor_sequential_dense_3_MatMul_ReadVariableOp_0[16][1] = 
{
  {1.2972877025604248047f},
  {-0.62708020210266113281f},
  {1.5989048480987548828f},
  {-0.15768533945083618164f},
  {-0.47212219238281250000f},
  {2.4136791229248046875f},
  {-0.36531269550323486328f},
  {0.14927618205547332764f},
  {-0.37016013264656066895f},
  {0.0016131198499351739883f},
  {-0.0015316570643335580826f},
  {-0.35469579696655273438f},
  {-0.51711624860763549805f},
  {0.00067038089036941528320f},
  {-0.025262776762247085571f},
  {0.25183671712875366211f}
};
static const float tensor_sequential_dense_3_BiasAdd_ReadVariableOp_0[1] = 
{-0.29452043771743774414f};
static const float tensor_sequential_dense_2_MatMul_ReadVariableOp_0[16][16] = 
{
  {0.41283398866653442383f, -0.22505725920200347900f, 0.30756542086601257324f, 0.34166797995567321777f, 0.024177972227334976196f, 0.42136320471763610840f, -0.014298627153038978577f, 0.32550749182701110840f, 0.14330224692821502686f, -0.0059226062148809432983f, 0.026754017919301986694f, 0.045480579137802124023f, -0.096794955432415008545f, -0.16313701868057250977f, 0.28194686770439147949f, 0.30424812436103820801f},
  {-0.29008853435516357422f, 0.16787531971931457520f, 0.31818786263465881348f, -0.13833521306514739990f, 0.26809078454971313477f, 0.065512835979461669922f, -0.41787061095237731934f, -0.30217605829238891602f, 0.30689659714698791504f, 0.0056427358649671077728f, -0.36439919471740722656f, -0.22573615610599517822f, 0.41178745031356811523f, 0.32398650050163269043f, -0.27402707934379577637f, -0.33047902584075927734f},
  {0.22748354077339172363f, -0.35538297891616821289f, -0.42494595050811767578f, -0.27974078059196472168f, -0.32135802507400512695f, 0.16985836625099182129f, -0.013101339340209960938f, 0.0080274259671568870544f, 0.17727085947990417480f, -0.24846354126930236816f, 0.32616057991981506348f, 0.35065695643424987793f, 0.081226140260696411133f, -0.21670590341091156006f, -0.25362855195999145508f, -0.10702589154243469238f},
  {-0.17976173758506774902f, -0.25812935829162597656f, 0.016735345125198364258f, -0.10261838883161544800f, -0.34856471419334411621f, -0.36576813459396362305f, -0.28288391232490539551f, -0.14129413664340972900f, -0.22686880826950073242f, 0.25959089398384094238f, 0.30106291174888610840f, -0.20835052430629730225f, -0.13237705826759338379f, 0.39533880352973937988f, 0.21336874365806579590f, -0.24344441294670104980f},
  {0.37199783325195312500f, -0.33691200613975524902f, 0.029942063614726066589f, 0.21379189193248748779f, 0.0081124436110258102417f, -0.26488360762596130371f, -0.32419973611831665039f, 0.066645346581935882568f, -0.19789585471153259277f, 0.054234005510807037354f, 0.24299988150596618652f, -0.20874266326427459717f, -0.26371940970420837402f, -0.24988724291324615479f, 0.23038975894451141357f, -0.27819651365280151367f},
  {-0.017733171582221984863f, 0.26143780350685119629f, -0.19211959838867187500f, -0.32339635491371154785f, -0.22781185805797576904f, 0.16052873432636260986f, 0.46784144639968872070f, -0.37145429849624633789f, 0.11859759688377380371f, 0.41149514913558959961f, 0.22318966686725616455f, -0.48565164208412170410f, 0.27967661619186401367f, -0.066572405397891998291f, -0.11893386393785476685f, -0.28935882449150085449f},
  {-0.40725463628768920898f, -0.015545397996902465820f, 0.28594884276390075684f, -0.42604193091392517090f, -0.10037073493003845215f, 0.27505114674568176270f, -0.11072933673858642578f, 0.14304962754249572754f, -0.14853468537330627441f, -0.11651378870010375977f, -0.017671287059783935547f, -0.31084269285202026367f, -0.086138188838958740234f, 0.023368299007415771484f, -0.34972822666168212891f, 0.25797548890113830566f},
  {0.36621475219726562500f, 0.28275451064109802246f, 0.13165631890296936035f, -0.56467139720916748047f, -0.10332390666007995605f, -0.28078567981719970703f, 0.14524619281291961670f, 0.38116294145584106445f, -0.41215479373931884766f, 0.25222757458686828613f, -0.14287525415420532227f, -0.66327852010726928711f, 0.049865543842315673828f, -0.30756881833076477051f, -0.55967319011688232422f, 0.093659445643424987793f},
  {0.092796675860881805420f, 0.0013883378123864531517f, -0.17918802797794342041f, -0.53769338130950927734f, 0.21079109609127044678f, -0.31631392240524291992f, -0.49506786465644836426f, 0.50014078617095947266f, -0.17576986551284790039f, 0.32306748628616333008f, -0.81512463092803955078f, -0.046426799148321151733f, 0.29891350865364074707f, -0.073050670325756072998f, -0.91432082653045654297f, -0.062576226890087127686f},
  {-0.34948804974555969238f, -0.16995239257812500000f, 0.41554045677185058594f, 0.12231842428445816040f, -0.048924405127763748169f, 0.28595042228698730469f, 0.063787125051021575928f, 0.22244259715080261230f, 0.49554854631423950195f, 0.10231556743383407593f, -0.026822734624147415161f, 0.015667768195271492004f, -0.046628363430500030518f, -0.023354614153504371643f, -0.10406330972909927368f, -0.17113618552684783936f},
  {-0.051866292953491210938f, 0.065128058195114135742f, -0.38439375162124633789f, 0.088195078074932098389f, -0.35681086778640747070f, -0.099369883537292480469f, 0.15202003717422485352f, 0.18064846098423004150f, 0.024574868381023406982f, 0.40235483646392822266f, 0.19979193806648254395f, -0.31015735864639282227f, -0.057944029569625854492f, 0.30304294824600219727f, 0.051470369100570678711f, -0.10529446601867675781f},
  {0.26585391163825988770f, 0.29343804717063903809f, 0.37717553973197937012f, -0.37491175532341003418f, -0.076186031103134155273f, -0.29907661676406860352f, -0.42803356051445007324f, 0.34447875618934631348f, 0.39109995961189270020f, -0.21147549152374267578f, -0.062462702393531799316f, 0.038164079189300537109f, -0.13709197938442230225f, -0.39164501428604125977f, -0.056454591453075408936f, -0.063040494918823242188f},
  {0.14609393477439880371f, 0.42725279927253723145f, -0.087008804082870483398f, 0.28389593958854675293f, 0.15526160597801208496f, -0.41417294740676879883f, 0.38390949368476867676f, -0.26894736289978027344f, 0.027328610420227050781f, -0.19263827800750732422f, -0.032239973545074462891f, -0.17510873079299926758f, 0.11973860859870910645f, 0.062072217464447021484f, -0.22950136661529541016f, 0.031165480613708496094f},
  {0.39238569140434265137f, -0.25646972656250000000f, -0.12794761359691619873f, 0.53718340396881103516f, -0.23797668516635894775f, 0.23976649343967437744f, 0.70503330230712890625f, 0.27136656641960144043f, 0.11554005742073059082f, -0.13165597617626190186f, 0.054895754903554916382f, -0.20641191303730010986f, -0.11311519145965576172f, 0.41079643368721008301f, -0.39498230814933776855f, 0.35244902968406677246f},
  {-0.83518689870834350586f, 0.80129420757293701172f, -0.19612596929073333740f, 0.15426120162010192871f, 0.00022045150399208068848f, -0.13680878281593322754f, -0.39171379804611206055f, 0.12140864133834838867f, 0.11666047573089599609f, -0.34515386819839477539f, 0.36848452687263488770f, 0.66215771436691284180f, 0.088304013013839721680f, -0.035304397344589233398f, -0.19620370864868164062f, 0.052288088947534561157f},
  {0.49371212720870971680f, -1.6152546405792236328f, -0.0031141957733780145645f, -0.36759042739868164062f, -0.92951625585556030273f, 0.091770082712173461914f, 0.33846402168273925781f, 0.46806702017784118652f, -0.61232942342758178711f, 0.14138969779014587402f, -0.65237051248550415039f, -1.0197261571884155273f, -0.30816128849983215332f, 0.049875430762767791748f, 0.37721395492553710938f, -0.35388457775115966797f}
};
static const float tensor_sequential_dense_2_BiasAdd_ReadVariableOp_0[16] = 
{0.36660102009773254395f, 0.11381757259368896484f, -0.75687468051910400391f, 0.18531464040279388428f, -0.029040932655334472656f, -0.61352527141571044922f, 0.26283076405525207520f, -0.35308963060379028320f, 0.37201759219169616699f, -0.31811705231666564941f, -0.075167916715145111084f, 0.21332006156444549561f, 0.00094045349396765232086f, 0.037537798285484313965f, 0.0053357174620032310486f, -0.025676205754280090332f};
static const float tensor_sequential_dense_1_MatMul_ReadVariableOp_0[16][16] = 
{
  {0.013643980026245117188f, 0.033432900905609130859f, -0.029527395963668823242f, -0.13489896059036254883f, 0.028417587280273437500f, -0.29607331752777099609f, 0.22582951188087463379f, 0.12684515118598937988f, -0.23916198313236236572f, 0.14909723401069641113f, 0.10462877154350280762f, 0.27682116627693176270f, 0.068828731775283813477f, -0.37384879589080810547f, 0.29127964377403259277f, -0.19924294948577880859f},
  {-0.042663633823394775391f, -0.33820247650146484375f, -0.27401226758956909180f, 0.15863284468650817871f, 0.11139033734798431396f, -0.20407210290431976318f, 0.11738833785057067871f, 0.14194652438163757324f, -0.16058364510536193848f, 0.17258042097091674805f, 0.24445126950740814209f, -0.16404539346694946289f, -0.38825941085815429688f, 0.044959858059883117676f, -1.7678430080413818359f, 0.76214355230331420898f},
  {-0.054042130708694458008f, 0.21107736229896545410f, -0.037984460592269897461f, -0.17321771383285522461f, -0.25492832064628601074f, -0.016174137592315673828f, 0.38673129677772521973f, -0.42755562067031860352f, 0.069296628236770629883f, 0.16343596577644348145f, 0.21429273486137390137f, -0.30229902267456054688f, -0.16893818974494934082f, -0.0037200748920440673828f, 0.31557658314704895020f, 0.048740744590759277344f},
  {0.043682016432285308838f, 0.31577321887016296387f, -0.14453998208045959473f, -0.41604629158973693848f, 0.17982493340969085693f, 0.13769827783107757568f, 0.056575179100036621094f, -0.13242943584918975830f, -0.37376847863197326660f, 0.42456626892089843750f, -0.079085610806941986084f, 0.12403997778892517090f, -0.16772431135177612305f, -0.13695262372493743896f, -0.58361423015594482422f, -0.35229846835136413574f},
  {0.048344522714614868164f, -0.0032434463500976562500f, 0.36392149329185485840f, -0.32569187879562377930f, -0.34881609678268432617f, -0.046608150005340576172f, -0.12427347898483276367f, 0.37672731280326843262f, 0.36159017682075500488f, 0.16472902894020080566f, 0.013953477144241333008f, -0.22791479527950286865f, -0.24928666651248931885f, -0.060866594314575195312f, 0.32282534241676330566f, -0.053760617971420288086f},
  {0.36481174826622009277f, -0.12308469414710998535f, 0.32461240887641906738f, 0.12485501170158386230f, 0.25642928481101989746f, -0.23781101405620574951f, -0.12941020727157592773f, -0.23967188596725463867f, -0.27795159816741943359f, -0.053800135850906372070f, -0.24069425463676452637f, -0.034395694732666015625f, 0.21790441870689392090f, 0.021083623170852661133f, -0.12970721721649169922f, -0.38191851973533630371f},
  {0.069880098104476928711f, 0.082344502210617065430f, -0.42073869705200195312f, -0.25549942255020141602f, 0.025542378425598144531f, -0.34171485900878906250f, 0.11079254746437072754f, -0.29280263185501098633f, -0.078157782554626464844f, 0.12596276402473449707f, 0.10683187842369079590f, 0.11874166131019592285f, -0.41745448112487792969f, 0.17594012618064880371f, -0.20275294780731201172f, -0.31907171010971069336f},
  {0.39637580513954162598f, 0.19267699122428894043f, -0.071714043617248535156f, -0.29479634761810302734f, -0.52679157257080078125f, 0.25795701146125793457f, 0.071111530065536499023f, -0.038944661617279052734f, -0.43192040920257568359f, 0.61632621288299560547f, 0.059421028941869735718f, -0.030182421207427978516f, -0.29558408260345458984f, -0.28937822580337524414f, -0.51292085647583007812f, 0.069358013570308685303f},
  {0.32224348187446594238f, 0.42041197419166564941f, -0.16650113463401794434f, -0.018822103738784790039f, -0.24025166034698486328f, -0.30517026782035827637f, -0.14022132754325866699f, -0.053801089525222778320f, -0.088299483060836791992f, 0.31990525126457214355f, 0.021155059337615966797f, -0.17789751291275024414f, 0.042208671569824218750f, 0.20984157919883728027f, 0.35159507393836975098f, -0.17321524024009704590f},
  {-0.073139458894729614258f, -0.32346150279045104980f, -0.062620520591735839844f, -0.22248886525630950928f, -0.30987498164176940918f, -0.058503419160842895508f, -0.069575577974319458008f, -0.37827140092849731445f, 0.17308235168457031250f, 0.48004224896430969238f, 0.29093146324157714844f, -0.21183668076992034912f, -0.055173307657241821289f, 0.042085886001586914062f, -0.48385867476463317871f, -0.25580891966819763184f},
  {-0.21227069199085235596f, 0.31243821978569030762f, -0.084112763404846191406f, -0.24625341594219207764f, 0.14295318722724914551f, 0.24067649245262145996f, -0.059999823570251464844f, 0.17201146483421325684f, -0.36139577627182006836f, -0.21991124749183654785f, 0.15673705935478210449f, 0.17275074124336242676f, -0.14665338397026062012f, 0.093373030424118041992f, -0.10483485460281372070f, 0.24290868639945983887f},
  {-0.40894758701324462891f, -0.43479928374290466309f, -0.29743579030036926270f, 0.053500376641750335693f, 0.26512810587882995605f, -0.031388957053422927856f, -0.33058238029479980469f, 0.45964747667312622070f, 0.31908160448074340820f, 0.074363447725772857666f, -0.30278906226158142090f, -0.39999213814735412598f, -0.25315231084823608398f, 0.22611922025680541992f, -0.34541672468185424805f, -0.047717191278934478760f},
  {0.35101866722106933594f, -0.060845382511615753174f, -0.19616137444972991943f, 0.31371122598648071289f, 0.12073540687561035156f, -0.039853852242231369019f, -0.34956374764442443848f, -0.51217448711395263672f, -0.36256417632102966309f, 0.58647584915161132812f, -0.20467996597290039062f, 0.16522791981697082520f, 0.11114665865898132324f, -0.43641141057014465332f, -0.29437255859375000000f, -0.26642483472824096680f},
  {-0.35723486542701721191f, -0.27877926826477050781f, 0.37140837311744689941f, 0.34072467684745788574f, -0.031085878610610961914f, 0.23713490366935729980f, -0.35785874724388122559f, -0.23960570991039276123f, 0.34866103529930114746f, 0.21114179491996765137f, -0.016256839036941528320f, 0.34732773900032043457f, -0.41576611995697021484f, -0.17148888111114501953f, 0.37510964274406433105f, -0.089446991682052612305f},
  {0.045905709266662597656f, 0.090807646512985229492f, -0.097500920295715332031f, 0.076633363962173461914f, 0.26101610064506530762f, 0.029731482267379760742f, -0.29402992129325866699f, -0.25121939182281494141f, 0.28878018260002136230f, -0.28921914100646972656f, -0.17557659745216369629f, -0.12481549382209777832f, -0.066362798213958740234f, -0.26773709058761596680f, 0.39735099673271179199f, -0.25261002779006958008f},
  {-0.25661814212799072266f, -0.16173008084297180176f, 0.23831756412982940674f, -0.36485952138900756836f, 0.019791912287473678589f, -0.30148687958717346191f, -0.20785404741764068604f, -0.13818219304084777832f, 0.11146359145641326904f, -0.25362542271614074707f, -0.36120870709419250488f, -0.25144279003143310547f, -0.26631087064743041992f, 0.080435059964656829834f, 0.12373568862676620483f, 0.25989282131195068359f}
};
static const float tensor_sequential_dense_1_BiasAdd_ReadVariableOp_0[16] = 
{-0.0017334333388134837151f, 2.0216451957821846008e-05f, -0.0031614736653864383698f, -0.013475887477397918701f, 0.59730416536331176758f, -0.054578579962253570557f, 0.0000000000000000000f, 0.21080234646797180176f, 0.27335557341575622559f, -0.69158107042312622070f, -0.0029327194206416606903f, -0.0031621747184544801712f, 0.0000000000000000000f, 0.063538581132888793945f, 0.43120419979095458984f, -0.011676709167659282684f};
static const float tensor_sequential_dense_MatMul_ReadVariableOp_0[1][16] = 
{
  {-0.41099774837493896484f, 0.14983192086219787598f, -0.066318929195404052734f, 0.29077735543251037598f, -0.14144769310951232910f, -0.10011962056159973145f, -0.43353676795959472656f, 0.34298464655876159668f, -0.14417132735252380371f, 0.51057040691375732422f, -0.024497210979461669922f, 0.28607276082038879395f, 0.25653749704360961914f, -0.28970101475715637207f, -0.19560214877128601074f, 0.048503369092941284180f}
};
static const float tensor_sequential_dense_BiasAdd_ReadVariableOp_0[16] = 
{0.0000000000000000000f, -0.017079401761293411255f, 0.0000000000000000000f, -0.48654815554618835449f, 0.0000000000000000000f, 0.0000000000000000000f, 0.0000000000000000000f, -0.62179750204086303711f, 0.0000000000000000000f, -0.70171350240707397461f, 0.0000000000000000000f, 0.13951160013675689697f, -0.42775586247444152832f, 0.0000000000000000000f, 0.0000000000000000000f, 0.067999407649040222168f};
static const int64_t tensor_const_fold_opt__14[1] = 
{-1};
union tensor_union_0 {
float tensor_sequential_ExpandDims_0[1][1];
float tensor_sequential_dense_Relu_0[1][16];
float tensor_sequential_dense_1_Relu_0[1][16];
float tensor_sequential_dense_2_Relu_0[1][16];
};
static union tensor_union_0 tu0;

union tensor_union_1 {
float tensor_sequential_dense_MatMul_Gemm__6_0[1][16];
float tensor_sequential_dense_1_MatMul_Gemm__7_0[1][16];
float tensor_sequential_dense_2_MatMul_Gemm__8_0[1][16];
};
static union tensor_union_1 tu1;


static inline void node_sequential_ExpandDims( const float tensor_x[1], const int64_t tensor_const_fold_opt__14[1], float tensor_sequential_ExpandDims_0[1][1] )
{
	/* Unsqueeze */
	float *data = (float*)tensor_x;
	float *expanded= (float*)tensor_sequential_ExpandDims_0;
	for( uint32_t i=0; i<1; i++ )
		expanded[i] = data[i];

}

static inline void node_sequential_dense_MatMul_Gemm__6( const float tensor_sequential_ExpandDims_0[1][1], const float tensor_sequential_dense_MatMul_ReadVariableOp_0[1][16], const float tensor_sequential_dense_BiasAdd_ReadVariableOp_0[16], float tensor_sequential_dense_MatMul_Gemm__6_0[1][16] )
{
	/* Gemm */
	/* alpha   = 1.0000000000000000000
	   beta    = 1.0000000000000000000
	   transA  = 0
	   transB  = 0
	 */
	const int M = 1;
	const int K = 1;
	const int N = 16;
	float (*A)[1]  = (float(*)[1])tensor_sequential_ExpandDims_0;
	float (*Y)[16]  = (float(*)[16])tensor_sequential_dense_MatMul_Gemm__6_0;
	float alpha = 1.0000000000000000000;
	float beta = 1.0000000000000000000;
	float (*C)[16]  = (float(*)[16])tensor_sequential_dense_BiasAdd_ReadVariableOp_0;
	for( uint32_t r=0; r<M; r++ )
		for( uint32_t c=0; c<N; c++ ) {
			float ABrc = 0;
			for( uint32_t i=0; i<K; i++ ) {
				float B = tensor_sequential_dense_MatMul_ReadVariableOp_0[i][c];
				ABrc += A[r][i] * B;
			}
			float tmp = ABrc * alpha;
			tmp += C[0][c] * beta;
			Y[r][c] = tmp;
	}
}

static inline void node_sequential_dense_Relu( const float tensor_sequential_dense_MatMul_Gemm__6_0[1][16], float tensor_sequential_dense_Relu_0[1][16] )
{
	/*Relu*/
	float *X = (float*)tensor_sequential_dense_MatMul_Gemm__6_0;
	float *Y = (float*)tensor_sequential_dense_Relu_0;
	for( uint32_t i=0; i<16; i++ )
		Y[i] = X[i] > 0 ? X[i] : 0;

}

static inline void node_sequential_dense_1_MatMul_Gemm__7( const float tensor_sequential_dense_Relu_0[1][16], const float tensor_sequential_dense_1_MatMul_ReadVariableOp_0[16][16], const float tensor_sequential_dense_1_BiasAdd_ReadVariableOp_0[16], float tensor_sequential_dense_1_MatMul_Gemm__7_0[1][16] )
{
	/* Gemm */
	/* alpha   = 1.0000000000000000000
	   beta    = 1.0000000000000000000
	   transA  = 0
	   transB  = 0
	 */
	const int M = 1;
	const int K = 16;
	const int N = 16;
	float (*A)[16]  = (float(*)[16])tensor_sequential_dense_Relu_0;
	float (*Y)[16]  = (float(*)[16])tensor_sequential_dense_1_MatMul_Gemm__7_0;
	float alpha = 1.0000000000000000000;
	float beta = 1.0000000000000000000;
	float (*C)[16]  = (float(*)[16])tensor_sequential_dense_1_BiasAdd_ReadVariableOp_0;
	for( uint32_t r=0; r<M; r++ )
		for( uint32_t c=0; c<N; c++ ) {
			float ABrc = 0;
			for( uint32_t i=0; i<K; i++ ) {
				float B = tensor_sequential_dense_1_MatMul_ReadVariableOp_0[i][c];
				ABrc += A[r][i] * B;
			}
			float tmp = ABrc * alpha;
			tmp += C[0][c] * beta;
			Y[r][c] = tmp;
	}
}

static inline void node_sequential_dense_1_Relu( const float tensor_sequential_dense_1_MatMul_Gemm__7_0[1][16], float tensor_sequential_dense_1_Relu_0[1][16] )
{
	/*Relu*/
	float *X = (float*)tensor_sequential_dense_1_MatMul_Gemm__7_0;
	float *Y = (float*)tensor_sequential_dense_1_Relu_0;
	for( uint32_t i=0; i<16; i++ )
		Y[i] = X[i] > 0 ? X[i] : 0;

}

static inline void node_sequential_dense_2_MatMul_Gemm__8( const float tensor_sequential_dense_1_Relu_0[1][16], const float tensor_sequential_dense_2_MatMul_ReadVariableOp_0[16][16], const float tensor_sequential_dense_2_BiasAdd_ReadVariableOp_0[16], float tensor_sequential_dense_2_MatMul_Gemm__8_0[1][16] )
{
	/* Gemm */
	/* alpha   = 1.0000000000000000000
	   beta    = 1.0000000000000000000
	   transA  = 0
	   transB  = 0
	 */
	const int M = 1;
	const int K = 16;
	const int N = 16;
	float (*A)[16]  = (float(*)[16])tensor_sequential_dense_1_Relu_0;
	float (*Y)[16]  = (float(*)[16])tensor_sequential_dense_2_MatMul_Gemm__8_0;
	float alpha = 1.0000000000000000000;
	float beta = 1.0000000000000000000;
	float (*C)[16]  = (float(*)[16])tensor_sequential_dense_2_BiasAdd_ReadVariableOp_0;
	for( uint32_t r=0; r<M; r++ )
		for( uint32_t c=0; c<N; c++ ) {
			float ABrc = 0;
			for( uint32_t i=0; i<K; i++ ) {
				float B = tensor_sequential_dense_2_MatMul_ReadVariableOp_0[i][c];
				ABrc += A[r][i] * B;
			}
			float tmp = ABrc * alpha;
			tmp += C[0][c] * beta;
			Y[r][c] = tmp;
	}
}

static inline void node_sequential_dense_2_Relu( const float tensor_sequential_dense_2_MatMul_Gemm__8_0[1][16], float tensor_sequential_dense_2_Relu_0[1][16] )
{
	/*Relu*/
	float *X = (float*)tensor_sequential_dense_2_MatMul_Gemm__8_0;
	float *Y = (float*)tensor_sequential_dense_2_Relu_0;
	for( uint32_t i=0; i<16; i++ )
		Y[i] = X[i] > 0 ? X[i] : 0;

}

static inline void node_sequential_dense_3_MatMul_Gemm__9( const float tensor_sequential_dense_2_Relu_0[1][16], const float tensor_sequential_dense_3_MatMul_ReadVariableOp_0[16][1], const float tensor_sequential_dense_3_BiasAdd_ReadVariableOp_0[1], float tensor_dense_3[1][1] )
{
	/* Gemm */
	/* alpha   = 1.0000000000000000000
	   beta    = 1.0000000000000000000
	   transA  = 0
	   transB  = 0
	 */
	const int M = 1;
	const int K = 16;
	const int N = 1;
	float (*A)[16]  = (float(*)[16])tensor_sequential_dense_2_Relu_0;
	float (*Y)[1]  = (float(*)[1])tensor_dense_3;
	float alpha = 1.0000000000000000000;
	float beta = 1.0000000000000000000;
	float (*C)[1]  = (float(*)[1])tensor_sequential_dense_3_BiasAdd_ReadVariableOp_0;
	for( uint32_t r=0; r<M; r++ )
		for( uint32_t c=0; c<N; c++ ) {
			float ABrc = 0;
			for( uint32_t i=0; i<K; i++ ) {
				float B = tensor_sequential_dense_3_MatMul_ReadVariableOp_0[i][c];
				ABrc += A[r][i] * B;
			}
			float tmp = ABrc * alpha;
			tmp += C[0][0] * beta;
			Y[r][c] = tmp;
	}
}


void entry(const float tensor_x[1], float tensor_dense_3[1][1]) {
	node_sequential_ExpandDims( tensor_x, tensor_const_fold_opt__14, tu0.tensor_sequential_ExpandDims_0);
	node_sequential_dense_MatMul_Gemm__6( tu0.tensor_sequential_ExpandDims_0, tensor_sequential_dense_MatMul_ReadVariableOp_0, tensor_sequential_dense_BiasAdd_ReadVariableOp_0, tu1.tensor_sequential_dense_MatMul_Gemm__6_0);
	node_sequential_dense_Relu( tu1.tensor_sequential_dense_MatMul_Gemm__6_0, tu0.tensor_sequential_dense_Relu_0);
	node_sequential_dense_1_MatMul_Gemm__7( tu0.tensor_sequential_dense_Relu_0, tensor_sequential_dense_1_MatMul_ReadVariableOp_0, tensor_sequential_dense_1_BiasAdd_ReadVariableOp_0, tu1.tensor_sequential_dense_1_MatMul_Gemm__7_0);
	node_sequential_dense_1_Relu( tu1.tensor_sequential_dense_1_MatMul_Gemm__7_0, tu0.tensor_sequential_dense_1_Relu_0);
	node_sequential_dense_2_MatMul_Gemm__8( tu0.tensor_sequential_dense_1_Relu_0, tensor_sequential_dense_2_MatMul_ReadVariableOp_0, tensor_sequential_dense_2_BiasAdd_ReadVariableOp_0, tu1.tensor_sequential_dense_2_MatMul_Gemm__8_0);
	node_sequential_dense_2_Relu( tu1.tensor_sequential_dense_2_MatMul_Gemm__8_0, tu0.tensor_sequential_dense_2_Relu_0);
	node_sequential_dense_3_MatMul_Gemm__9( tu0.tensor_sequential_dense_2_Relu_0, tensor_sequential_dense_3_MatMul_ReadVariableOp_0, tensor_sequential_dense_3_BiasAdd_ReadVariableOp_0, tensor_dense_3);
}
