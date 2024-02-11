import style from './AdminQuestionsManage.module.css'
import { useNavigate } from "react-router-dom"

const AdminQuestionsManage = () => {
  const navigate = useNavigate();
  const testTypeArray = ["education", "psycho", "funny"]

  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>
          <div>
          Управление
          </div>
          <div>
          базой вопросов
          </div>
        </div>
        <div className={style.imageBox}>
          <div>
            <img src={`${testTypeArray[0]}.png`} alt={`${testTypeArray[0]}.png`} />
            <div className={style.imageCaption} > Education </div>
          </div>
          <div>
            <img src={`${testTypeArray[1]}.png`} alt={`${testTypeArray[1]}.png`} />
            <div className={style.imageCaption} >Psychological</div>
          </div>
          <div>
            <img src={`${testTypeArray[2]}.png`} alt={`${testTypeArray[2]}.png`} />
            <div className={style.imageCaption} >Funny</div>
          </div>
        </div>
        <div className={style.placeButton}>
          <button className={style.flatButton} onClick={ ()=>navigate(-1)} >Back</button>
        </div>
      </div>
  );
}

export default AdminQuestionsManage;
